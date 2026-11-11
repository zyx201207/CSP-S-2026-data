#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long N=5e5+5,inf=1e18;
long long a[N],ss[N];
long long n,m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //cout<<s<<"\n";
    sort(a+1,a+n+1);
    long long ans=0;
    a[n+1]=inf+1;
    for(int i=1;i<=n;i++)
    {
        //if(i!=1)
        //{
        s+=a[i];
            long long d=a[i]*i-s;
            //if(i-1==313324||i-1==315275)cout<<d<<"\n";
            //cout<<i<<" "<<d<<"\n";
            if(d<=m)ans=max(ans,(long long)i);
        //}
        //}
    }
    cout<<ans;
    return 0;
}
