#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=1e6+10;
int a[maxn],wz[maxn],cnt[maxn],w[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        wz[a[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        int l=i;
        while(l<=n)
        {
            if(wz[a[l]]==0||wz[a[l]]<=l)
            {
                cnt[a[l]]++;
                l++;
            }
            else 
            {
                l=wz[a[l]];
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    return 0;
}