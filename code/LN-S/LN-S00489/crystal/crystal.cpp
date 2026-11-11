#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
long long c[500000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];

    b[0]=0;
    for(int i=1;i<=n;++i){
        b[i]=b[i-1]+a[i];
    }
    long long ans=-1e15;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if((j-i)*a[j]-(b[j-1]-b[i-1])==m){
                long long t=j-i+1;
                ans=max(ans,t);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
