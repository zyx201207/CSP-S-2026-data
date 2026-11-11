#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int che1,che2;
    string wei1,wei2;
    cin>>che1>>wei1>>che2>>wei2;
    int flag1=0,flag2=0,flag3=0,flag4=0;
    int hang1=(wei1[0]-'0')*10+(wei1[1]-'0');
    int hang2=(wei2[0]-'0')*10+(wei2[1]-'0');
    char zuo1=wei1[2];
    char zuo2=wei2[2];
    if(che1==che2)
    {
        flag1=1;
    }
    if(hang1==hang2)
    {
        flag2=1;
    }
    if(zuo1>='A'&&zuo1<='C'&&zuo2>='A'&&zuo2<='C'||zuo1>='D'&&zuo1<='F'&&zuo2>='D'&&zuo2<='F')
    {
        flag3=1;
    }
    if(abs(zuo1-zuo2)==1||(zuo1=='D'&&zuo2=='F')||(zuo1=='F'&&zuo2=='D'))
    {
        flag4=1;
    }
    if(flag1==1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(flag1==1&&flag2==1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(flag1==1&&flag2==1&&flag3==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(flag1==1&&flag2==1&&flag3==1&&flag4==1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
