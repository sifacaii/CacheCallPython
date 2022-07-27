Class Utils.CALLPYTHON Extends %RegisteredObject
{
/// d ##class(Utils.CALLPYTHON).CALLPYTHON()
ClassMethod CALLPYTHON()
{
    SET str = "这是一段测试文字"
    SET dll=^%SYS("bindir")_"CallPython.dll"
    SET x=$ZF(-3,dll)
    SET str = $ZCVT(str, "O", "UTF8")
    SET r=$ZF(-3,"","CALLPYTHON",str)
    SET r = $zcvt(r, "I", "UTF8")
    WRITE r,!
    SET x=$ZF(-3,"")
}

}
