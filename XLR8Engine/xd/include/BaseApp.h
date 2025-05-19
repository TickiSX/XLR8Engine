#pragma once
#include "Prerequisites.h"

class BaseApp
{
public:
	BaseApp() = default;
	~BaseApp();

	int run();

	bool init();

	void update();

	void render();

	void destroy();

	void handleEvents();

private:

};

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{
}