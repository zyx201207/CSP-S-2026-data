#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    //8:35-9:08
    //文件读入输出
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //Q1 两张车票对应的座位是否在同一节车厢
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    //Q2 两张车票对应的座位是否在同一节车厢的同一排
    if(s1[0]!=s2[0] || s1[1]!=s2[1])
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    //Q3 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
    {
        if(s2[2]=='D' || s2[2]=='F')
        {
            cout<<"00"<<endl;
            return 0;
        }
        cout<<1;
    }
    if(s1[2]=='D' || s1[2]=='F')
    {
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
        {
            cout<<"00"<<endl;
            return 0;
        }
        cout<<1;
    }
    //Q4 两张车票对应的座位是否相邻
    if(s1[2]=='D' || s1[2]=='F')
    {
        cout<<1<<endl;
        return 0;
    }
    if(s1[2]=='B' || s2[2]=='B')
    {
        //如果他们在A-C处相邻，那么一定会有一个在B处
        cout<<1<<endl;
        return 0;
    }
    //已经把所有特殊情况都判断了
    cout<<0<<endl;
    return 0;
}