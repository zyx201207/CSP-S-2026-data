#include<bits/stdc++.h>
using namespace std;
bool t1=0,t2=0,t3=0,t4=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2,ch1,ch2;char m1,m2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)t1=1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
            ch1+=s1[i];
        else m1+=s1[i];
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]>='0'&&s2[i]<='9')
            ch2+=s2[i];
        else m2+=s2[i];
    }
    if(ch1==ch2)t2=1;
    if(t2==1&&((m1=='A'&&m2=='B')||(m1=='B'&&m2=='A')||(m1=='C'&&m2=='B')||(m1=='B'&&m2=='C')||(m1=='D'&&m2=='F')||(m1=='F'&&m2=='D')))
    {
        t3=1;
        t4=1;
    }
    else if(((m1=='A'&&m2=='C')||(m1=='C'&&m2=='A'))&&t2==1)t3=1;
    cout<<t1<<t2<<t3<<t4;
    return 0;
}
