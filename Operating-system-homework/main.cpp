#include "systemwork.h"

int main()
{
    while (1)
    {
        cout << "please select algorithm:|FSA|PSA|TSA|SSA|RSSA|HSA|MSA|" << endl; //输入算法类型
        string str;
        cin >> str;
        if (str == "exit")
            exit(0);
        initdata(data); //初始化数据
        select(str[0]); //算法实现
    }
    return 0;
}