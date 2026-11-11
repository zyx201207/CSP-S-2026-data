#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x_1,x_2,y_1,y_2;
    bool s=1;
    string m,n;
    int sum=0,num=0;
    cin>>x_1>>x_2>>y_1>>y_2;
    if(x_1==y_1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
        s=0;
    }

    for(int i=0;i<3;i++)
    {
        if(x_2[i]>='0' && x_2[i]<='9')
        {
            sum+='x_2[i]-0';
        }
    }
    for(int i=0;i<3;i++)
    {
        if(y_2[i]>='0' && y_2[i]<='9')
        {
             num+='y_2[i]-0';
        }
    }
    if(s==0)
    {
        cout<<"0";
    }
    if else(sum==num)
    {
        cout<<"1";
    }

    for(int i=0;i<3;i++)
    {
        if(x_2[i]>='A' && x_2[i]<='z')
        {
            m=x_2[i];
        }
    }
    for(int i=0;i<3;i++)
    {
        if(y2[i]>='A' && y2[i]<='Z')
        {
            n=y_2[i];
        }
    }
    if(s==0)
    {
        cout<<0;
    }
    else if(((m-'0')-(n-'0')==1 || (n-'0')-(m-'0')==1) && (n!='C' && m!='D') && (n!='D' && m!='C'))
    {
        cout<<1
    }

    if(s==0)
    {
        cout<<"0";
    }
    if else(x_2-y_2==1 || y_2-x_2==1)
    {
        cout<<1;
    }
    return 0;
}
