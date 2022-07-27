del test.exe CallPython.dll
gcc test.c -o test
gcc CallPython.c -shared -o  CallPython.dll -I D:\code\Python38\include D:\code\Python38\libs\python38.lib