#include<bits/stdc++.h>
using namespace std;
int ans=1,d,x;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool reduce=true;
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    d=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=d)
        {
            reduce=false;
        }

    }
    if(reduce)
    {
        while(m!=0)
        {
            x+=d;
            m-=x;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    int sum=0,num=0;
    for(int i=n/2;i>=1;i--)
    {
        if(a[n/2+1]!=a[i])
        {
            break;
        }
        num++;
    }
    for(int i=n/2+2;i<=n;i++)
    {
        if(a[n/2+1]!=a[i])
        {
            break;
        }
        num++;
    }
    for(int i=1;i<=n/2;i++)
    {
        sum+=a[n/2+1]-a[i];
    }
    if(sum<=m)
    {
        ans+=n/2+num;
        cout<<ans;
        return 0;
    }
    return 0;
}
