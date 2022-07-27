#define ZF_DLL
#include "cdzf.h"
#include <string.h>
#include "Python.h"

extern int test();
extern int callpy();

ZFBEGIN
  ZFENTRY("TEST","C",test)
  ZFENTRY("CALLPYTHON","C",callpy)
ZFEND

int test(args)
char *args;
{
  char *msg="this is test aaa";
  strcpy(args,msg);
  return ZF_SUCCESS;
}


int callpy(args)
char *args;
{
  Py_Initialize();//调用Py_Initialize()进行初始化
  //PyRun_SimpleString("import sys");
  //PyRun_SimpleString("sys.path.append(r'D:\\pyscript')");
  PyObject * pModule = NULL;
  PyObject * pFunc = NULL;
  PyObject *pReturn = NULL;

  pModule = PyImport_ImportModule("CallPython");//调用的Python文件名
  pFunc = PyObject_GetAttrString(pModule, "CallPython");//调用的函数名
  //创建参数:
  PyObject *pArgs = PyTuple_New(1);
  PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", args));

  pReturn=PyEval_CallObject(pFunc, pArgs);//调用函数,并传入参数pArgs
  // char* str = PyUnicode_AsUTF8(pReturn);
  // strcpy(args,str);
  char * result;
  PyArg_Parse(pReturn, "s", &result);
  strcpy(args,result);

  Py_Finalize();//调用Py_Finalize,和Py_Initialize相对应的.

  return ZF_SUCCESS;
}
