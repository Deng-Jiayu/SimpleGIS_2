#include "MainWindow.h"
#include <QDebug>
#include "ogrsf_frmts.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	pm.loadPlugins("D:/code/plugin");

	// 加载插件
	for (auto it = pm.plgs.begin(); it != pm.plgs.end(); it++) {
		qDebug() << ((*it).second->type());

		if ((*it).second->type() == "MenuPlugin") {
			MenuPlugin* p = (*it).second->getMenuPlugin();
			QMenu* pMenu = p->GetMenu();
			ui.menuBar->addMenu(pMenu);
		}
		else if ((*it).second->type() == "ToolBarPlugin") {
			ToolBarPlugin* p = (*it).second->getToolBarPlugin();
			QToolBar* pToolBar = p->getToolBar();
			ui.mainToolBar->addWidget(pToolBar);
		}
	}

	// 读取shp

	// 注册所需的所有格式驱动程序
	GDALAllRegister();

	GDALDataset* poDS;

	poDS = (GDALDataset*)GDALOpenEx("D:/code/landuse.shp", GDAL_OF_VECTOR, NULL, NULL, NULL);

	if (poDS == NULL) {
		qDebug() << "Open failed.";
		exit(1);
	}

	OGRLayer* poLayer;
	poLayer = poDS->GetLayerByName("landuse");

	for (auto& poFeature : poLayer) {
		for (auto&& oField : *poFeature) {
			switch (oField.GetType())
			{
			case OFTInteger:
				qDebug() << oField.GetInteger();
				break;
			case OFTInteger64:
				qDebug() << oField.GetInteger64();
				break;
			case OFTReal:
				qDebug() << oField.GetDouble();
				break;
			case OFTString:
				qDebug() << oField.GetAsString();
				break;
			default:
				qDebug() << oField.GetAsString();
				break;
			}
		}
	}

	// 显示至表格
	QTableView* tableView = new QTableView();
	QStandardItemModel* model = new QStandardItemModel();

	model->setHorizontalHeaderLabels({ "ID","name","type" });

	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	int i = 0;
	for (auto& poFeature : poLayer) {
		int j = 0;
		for (auto&& oField : *poFeature) {
			model->setItem(i, j, new QStandardItem(QString(oField.GetAsString())));
			j++;
		}
		i++;
	}
	tableView->setModel(model);

	tableView->show();

}
