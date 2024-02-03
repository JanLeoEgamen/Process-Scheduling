#include "MyForm.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace OPERATINGSYSTEMPROJECT;

using namespace std;
[STAThreadAttribute] 
int main()
{
	Application::Run(gcnew MyForm());
	return 0;
}