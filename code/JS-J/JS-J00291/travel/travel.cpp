#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[15];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    for(int i=1;i<=5;i++)
    {
        ans[i]=0;
    }
    if(a[0]==c[0]&&a[1]==c[1])
    {
        ans[1]=1;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&ans[1]==1)
    {
        ans[2]=1;
    }
    if(ans[2]==1)
    {
        if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
        {
            ans[3]=1;
        }
        else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
        {
            ans[3]=1;
        }
    }
    if(ans[3]==1)
    {
        if(b[2]-d[2]==1||d[2]-b[2]==1)
        {
            ans[4]=1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        cout<<ans[i];
    }
    return 0;
}
