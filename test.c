#include <Windows.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *msg = "aaaaaaaaaaa";
    // 运行时加载DLL库
	HMODULE module = LoadLibrary("CallPython.dll");
	if (module == NULL)
	{
		printf("CallPython.dll动态库失败\n");
		return;
	}
	typedef int(*AddFunc)(char *); // 定义函数指针类型
	AddFunc callpy; 
    // 导出函数地址
	callpy = (AddFunc)GetProcAddress(module, "callpy");

	int cd = callpy(msg);
	printf("dtdy: = %i,jg:%s\n",cd,msg);

	system("pause");
	return 0;
}