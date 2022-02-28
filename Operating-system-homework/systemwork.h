#include <bits\stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int data[100];
int length;
#define timechange 1
#define Max 123

typedef struct FSA
{
    int pro_num; //进程号
    int time;    //进程所需时间
} fsa;

typedef struct PSA
{
    int pro_num;  //进程号
    int time;     //进程所需时间
    int priority; //优先级
    bool operator<(const struct PSA &a) const
    {
        return priority < a.priority;
    }
} psa;

typedef struct TSA
{
    int pro_num; //进程号
    int time;    //进程所需时间
    bool operator<(const struct TSA &a) const
    {
        return time < a.time;
    }
} tsa;

typedef struct SSA
{
    int pro_num; //进程号
    int time;    //进程所需时间
    bool operator<(const struct SSA &a) const
    {
        return time < a.time;
    }
} ssa;

typedef struct RSSA
{
    int pro_num; //进程号
    int time;    //进程所需时间
    bool operator<(const struct RSSA &a) const
    {
        return time < a.time;
    }
} rssa;

typedef struct HSA
{
    int pro_num;  //进程号
    int time;     //进程所需时间
    int waittime; //等待时间
    float prinum; //优先数
    int finish;   //是否完成
    bool operator<(const struct HSA &a) const
    {
        return prinum > a.prinum;
    }
} hsa;

typedef struct MSA
{
    int pro_num;  //进程号
    int time;     //进程所需时间
    int priority; //优先级
    int waittime; //进程等待时间
    bool operator<(const struct MSA &a) const
    {
        return priority < a.priority;
    }
} msa;

void seehistory()
{
    cout << "see last data?(Y/N)" << endl; //查看历史记录
    char c;
    cin >> c;

    if (c == 'Y' || c == 'y')
    {
        //打开记事本并显示，让用户查看历史记录
        system("file.txt");
    }
}

void initdata(int data[])
{
    string s;
    char c[20];

    seehistory();

    memset(data, '\0', sizeof(int *));

    auto i = 0;
    cout << "please input process" << endl;
    while (1)
    {
        cin >> data[i];
        itoa(data[i], c, 10);
        s += c;
        s += " ";
        i++;
        if (getchar() == '\n')
            break;
    }

    ofstream file;
    file.open("file.txt", ios::app);

    file << s << endl;

    file.close();
    length = i;
}

void excute(msa p[], int num)
{
    for (auto i = 0; i < length; i++) //所有进程等待时间加一
    {
        p[i].waittime++;
        if (p[i].waittime > 4 && p[i].priority != Max + 1) //等待时间超过4个时间片则将优先级重新置为最高优先级队列
            p[i].priority = 0;
    }
    p[num].time -= timechange; //执行一个时间片时间
    if (p[num].time == 0 || p[num].time < 0)
    { //执行完成，不再执行
        p[num].priority = Max;
        p[num].time = 0;
        cout << "process number:" << p[num].pro_num << "\t"
             << "finish!" << endl;
    }
    p[num].waittime = 0; //执行一次后等待时间置为0
    p[num].priority++;   //优先级下降一个队列
    sort(p, p + length); //对进程重新排队
}

void FSA(int data[]) //先来先服务调度算法
{
    cout << "this is FSA algorithm" << endl;
    fsa p[100];
    for (auto i = 0; i < length; i++)
    {
        p[i].time = data[i];
        p[i].pro_num = i + 1;
    }

    for (auto i = 0; i < length; i++)
    {
        cout << "Excute process number:" << p[i].pro_num << "\t"
             << "process time:" << p[i].time;
        cout << endl;
    }

    system("pause");
}
void PSA(int data[]) //优先级调度算法
{
    cout << "this is PSA algorithm" << endl;
    psa p[100];

    for (auto i = 0; i < length; i++)
    {
        p[i].pro_num = i + 1;
        p[i].time = data[i];
        cout << "please input priority of process " << p[i].pro_num << ": ";
        cin >> p[i].priority;
    }

    auto i = 0;

    sort(p, p + length);

    getchar();

    while (p[length - 1].time)
    {
        if (p[i].time)
        {
            cout << "Excute:";
            cout << "process number:" << p[i].pro_num << "\t"
                 << "       process priority:" << p[i].priority << "\t"
                 << "process time:" << p[i].time << endl;
            p[i].time--;
            if (!p[i].time)
            {
                cout << "process " << p[i].pro_num << " finish!";
                i++;
            }
        }
        getchar();
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void TSA(int data[]) //时间片轮转调度算法
{
    cout << "this is TSA algorithm" << endl;
    tsa p[100];
    for (auto i = 0; i < length; i++)
    {
        p[i].time = data[i];
        p[i].pro_num = i + 1;
    }

    auto i = 0;

    sort(p, p + length);

    while (p[length - 1].time)
    {
        if (p[i].time)
        {
            cout << "Excute process num:    " << p[i].pro_num << "      need time:    " << p[i].time;
            p[i].time -= timechange;
            if (!p[i].time)
            {
                getchar();
                cout << "process " << p[i].pro_num << "  finish!";
            }
            getchar();
        }
        i++;
        if (i == length)
        {
            i = 0;
            cout << endl;
        }
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void SSA(int data[]) //短进程优先调度算法
{
    cout << "this is SSA algorithm" << endl;
    ssa p[100];
    for (auto i = 0; i < length; i++)
    {
        p[i].time = data[i];
        p[i].pro_num = i + 1;
    }

    sort(p, p + length);

    for (auto i = 0; i < length; i++)
    {
        cout << "process number:" << p[i].pro_num << "\t"
             << "process total time:" << p[i].time << "\t"
             << endl;
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void RSSA(int data[]) //最短剩余时间调度算法
{
    cout << "this is RSSA algorithm" << endl;
    rssa p[100];
    for (auto i = 0; i < length; i++)
    {
        p[i].time = data[i];
        p[i].pro_num = i + 1;
    }

    auto i = 0;

    while (p[length - 1].time)
    {
        cout << "insert?  ";
        auto c = getchar();
        if (c == 'y' || c == 'Y')
        {
            p[length].pro_num = length + 1;
            cout << "process time:";
            cin >> p[length].time;
            cout << "insert success! process number is " << p[length].pro_num << endl;
            length++;
            getchar();
        }
        else
        {
            sort(p, p + length);
            if (!p[i].time)
            {
                cout << "process number:" << p[i].pro_num << "\t"
                     << "finish!" << endl;
                i++;
                continue;
            }
            else
            {
                cout << "process number:" << p[i].pro_num << "\t"
                     << "process time:" << p[i].time << endl;
            }
            p[i].time--;
        }
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void HSA(int data[]) //最高响应比优先调度算法
{
    cout << "this is HSA algorithm" << endl;
    hsa p[100];

    for (auto i = 0; i < length; i++)
    {
        p[i].pro_num = i + 1;
        p[i].time = data[i];
        p[i].waittime = 0;
        p[i].prinum = 1;
        p[i].finish = 0;
    }

    auto i = 0;

    sort(p, p + length);

    while (p[0].time)
    {
        sort(p, p + length);
        if (p[0].time)
        {
            cout << "Excute:";
            cout << "process number:" << p[0].pro_num << "\t"
                 << "       process waittime:" << p[0].waittime << "\t"
                 << "       process pri:" << p[0].prinum << "\t"
                 << "process time:" << p[0].time;
            getchar();
            p[0].time--;

            for (auto j = 1; j < length; j++)
            {
                p[j].waittime++;
                if (!p[j].finish)
                    p[j].prinum = 1.0 * p[j].waittime / p[j].time + 1;
            }

            p[0].waittime = 0;

            p[0].prinum = 1;

            if (!p[0].time)
            {
                cout << "process " << p[0].pro_num << " finish!" << endl;
                p[0].finish = 1;
            }
            sort(p, p + length);
        }
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void MSA(int data[]) //多级反馈队列调度算法
{
    cout << "this is MSA algorithm" << endl;
    msa p[100];

    for (auto i = 0; i < length; i++)
    {
        p[i].pro_num = i + 1;
        p[i].time = data[i];
        p[i].priority = 0; //进程进入时全部放在最高优先级队列
        p[i].waittime = 0;
    }

    auto n = 0;

    while (p[0].time)
    {
        sort(p, p + length);
        auto mpriy = p[0].priority;
        for (auto i = 0; i < length; i++)
        {
            if (p[i].priority == mpriy) //优先级有相同的时候轮转执行，同时优先级低的后执行
                excute(p, i);
        }
        cout << "Excute:" << endl;
        for (auto i = 0; i < length; i++)
        {
            cout << "process number:" << p[i].pro_num << "\t"
                 << "process priority:" << p[i].priority << "\t"
                 << "process time:" << p[i].time << endl;
        }
    }
    cout << "The process is complete!" << endl;
    system("pause");
}
void select(char c)
{
    switch (c)
    {
    case 'F':
        FSA(data);
        break;
    case 'P':
        PSA(data);
        break;
    case 'T':
        TSA(data);
        break;
    case 'S':
        SSA(data);
        break;
    case 'R':
        RSSA(data);
        break;
    case 'H':
        HSA(data);
        break;
    case 'M':
        MSA(data);
        break;
    default:
        cout << "no exist algorithm,please try again" << endl;
        break;
    }
}
