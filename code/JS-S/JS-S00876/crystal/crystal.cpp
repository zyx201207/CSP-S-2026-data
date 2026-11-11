#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
long long n,m;
int a[N];
long long cnt=1,ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int t=log2(n);
    for(int j=2;j<=t;j++)
    {
        cnt=1;
        for(int i=j;i<=n;i++)
        {
            if(a[i]==a[i-1]) {cnt++;continue;}
            int need=(a[i]-a[i-1])*(i-1);
            if(need<=m) m-=need,cnt++;
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
