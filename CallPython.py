def CallPython(args):
	result = {
		'code':1,
		'msg':'',
		'data':''
	}
	try:
		import sys
		sys.path.append(r"D:\pyscript")
		import fibmodule
		result['data'] = fibmodule.fengfa(args)

	except Exception as exmsg:
		result['code'] = 1
		result['msg'] = str(exmsg)
	else:
		result['code'] = 0
		result['msg'] = '执行成功'

	import json
	return json.dumps(result,ensure_ascii=False)

if __name__ == "__main__":
	print(CallPython("aaa"))
