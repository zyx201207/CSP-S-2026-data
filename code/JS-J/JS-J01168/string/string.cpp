#include<bits/stdc++.h>
using namespace std;
int n,a[300000];
char c[300000];
long long sum,mid,l,r,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    mid=sum/2;
    long long nowl=0,nowr=0,x=1,y=n;
    char lc,rc;
    while(x<=y)
    {
        if(nowl==0)
        {
            l+=a[x],nowl=a[x],lc=c[x];
            x++;
        }
        if(nowr==0)
        {
            r+=a[y],nowr=a[y],rc=c[y];
            y--;
        }
        int t=min(nowl,nowr);
        if(lc!=rc)
        {
            ans+=t;
        }
        nowl-=t,nowr-=t;
    }
    cout<<ans;
    return 0;
}
