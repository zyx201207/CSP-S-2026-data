#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int t=1,a,b;
    if(c1==c2)
    {
        cout<<1;
    }
    for(int i=1;i<=3;i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            a=s1[i]-'0';
            b=s2[i]-'0';
            if(a!=b)
            {
                cout<<0;
                t=0;
            }
        }
        if(t==1)
        {
            cout<<1;
        }
        if(s1[i]>='A'&&s1[i]<='F')
        {
            if(s1[i]>='A'&&s1[i]<='C'&&s2[i]>='A'&&s2[i]<='C')
            {
                cout<<1;
                if((s1[i]+s2[i])%2==1)
                {
                    cout<<1;
                }
            }
            else if(s1[i]>='D'&&s1[i]<='F'&&s2[i]>='D'&&s2[i]<='F')
            {
                cout<<1<<1;
            }
            else
            {
                cout<<0<<0;
            }
        }
    }
    return 0;
}
