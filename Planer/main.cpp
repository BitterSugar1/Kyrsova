#include "WeeklyPlannerForm.h"

#include <windows.h>
using namespace Planer;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew WeeklyPlannerForm);
	return 0;
}