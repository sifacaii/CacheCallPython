def CallPython(args):
	result = {
		'code':1,
		'msg':'',
		'data':''
	}
	import json
	try:
		args = json.loads(args)
		modulePath = args['modulePath']
		funName = args['funName']
		params = args['params']
		import sys
		sys.path.append(modulePath)
		import fibmodule
		result['data'] = fibmodule.fengfa(funName,params)
	
	except Exception as exmsg:
		result['code'] = 1
		result['msg'] = str(exmsg)
	else:
		result['code'] = 0
		result['msg'] = '执行成功'

	
	return json.dumps(result,ensure_ascii=False)

if __name__ == "__main__":
	print(CallPython("aaa"))
