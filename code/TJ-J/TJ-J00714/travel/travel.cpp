#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int flag1,flag2,flag3;
int judge1()
{
    char a=s1[2],b=s2[2];
    if(((a<='C'&&b<='C')||(a>'C'&&b>'C'))&&flag1&&flag2)
    {
        return 1;
    }
    return 0;
}
int judge2()
{
    char a=s1[2],b=s2[2];
    if((abs(a-b)==1||(a=='A'&&b=='F'))&&flag1&&flag2&&flag3)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    flag1=(c1==c2),flag2=(s1.substr(0,2)==s2.substr(0,2)&&flag1),flag3=judge1();
    cout<<flag1<<flag2<<flag3<<judge2();
    return 0;
}
