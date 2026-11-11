#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+20;
int n,m;
int a[maxn];
int b[maxn];
int sum[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        memset(b,0,sizeof(b));
        int k=1;
        for(int j=i;j<=n;++j)
        {
            bool f=1;
            for(int x=1;x<=k;++x)
            {
                if(a[j]==b[x])
                {
                    f=0;
                    k=x;
                    break;
                }
            }
            if(f==1)
            {
                k++;
                b[k]=a[j];
            }
        }
        for(int j=1;j<=k;++j)sum[b[j]]++;
    }
    for(int i=1;i<=m;++i)cout<<sum[i]<<" ";
    return 0;
}