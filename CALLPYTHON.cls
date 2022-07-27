Class Utils.CALLPYTHON Extends %RegisteredObject
{
/// d ##class(Utils.CALLPYTHON).CALLPYTHON()
ClassMethod CALLPYTHON(funName As %String, params As %String) As %String
{
    SET args = ##class(%ArrayOfDataTypes).%New()
    Do args.SetAt("D:\pyscript","modulePath") //模块路径
    Do args.SetAt(funName,"funName") //方法名
    Do args.SetAt(params,"params") //参数值
    SET args = ##class(Utils.CacheJSON).Encode(args)
    SET args = $ZCVT(args, "O", "UTF8")
    
    SET dll=^%SYS("bindir")_"CallPython.dll"
    SET x=$ZF(-3,dll)    
    SET ret=$ZF(-3,"","CALLPYTHON",args)
    SET x=$ZF(-3,"")
        
    SET ret = $zcvt(ret, "I", "UTF8")

    Quit ret
}

}
