#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,b;
char a1[5],b1[5],c,d;
cin>>a;
for(int i=1;i<=3;i++)cin>>a1[i];
cin>>b;
for(int i=1;i<=3;i++)cin>>b1[i];
if(a1[3]>b1[3]){
    c=b1[3];
    d=a1[3];
}else
{
    c=a1[3];
    d=b1[3];
}
if(a!=b)
{
    cout<<"0000";
}else
{
    if((a1[1]==b1[1])&&(a1[2]==b1[2]))
    {
        if((c<67&&d<=67)||(c==68&&d==69))
        {
            if(c+1==d)
            {
                cout<<1111;
            }else
            {
                cout<<1110;
            }
        }else
        {
            cout<<1100;
        }
    }else
    {
        cout<<1000;
    }
}
return 0;
}
