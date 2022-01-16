#include "pluginManager.h"
#include <QDir>
#include <Windows.h>
#include <QDebug>

PluginManager::PluginManager() {}

PluginManager::~PluginManager() {}

void PluginManager::loadPlugins(QString subPath) {
	QDir plgPathDir = QString(subPath);
	qDebug() << "PluginManager::loadPlugins(QString subPath) subPath = " << subPath;
	if (!plgPathDir.exists()) {
		return;
	}
	QStringList filters;
	filters << QString("*.dll");
	plgPathDir.setFilter(QDir::Files | QDir::NoSymLinks);	// �������͹�������ֻΪ�ļ���ʽ
	plgPathDir.setNameFilters(filters);						// �����ļ����ƹ�������ֻΪfilters��ʽ
	int dirCount = plgPathDir.count();
	if (dirCount <= 0)
		return;
	QStringList stringList;
	QString absPath = plgPathDir.absolutePath();
	for (int i = 0; i < dirCount; i++) {
		QString filName = absPath + "/" + plgPathDir[i];
		qDebug() << filName;
		loadPlugin(filName);
	}
}

typedef MainInterface* (*InitType)();

void PluginManager::loadPlugin(QString plgPath) {
	HMODULE m = LoadLibraryA(plgPath.toStdString().c_str());

	if (m == NULL)return;

	void* addr = GetProcAddress(m, "Init");

	InitType f = (InitType)addr;
	MainInterface* iface = f();

	plgs[iface->name()] = iface;		// ���뵽map��
}