#include <bits/stdc++.h>

using namespace std;
const int maxn=5e5+1000;
long long ar[maxn],d[maxn];
int n;
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>ar[i];
    }
    sort(ar+1,ar+1+n);
    for(int i=1; i<=n; i++)
    {
        d[i]=d[i-1]+ar[i];
    }
    int ans=0;
    for(int r=n; r>=1; r--)
    {
        for(int l=0; l<=r; l++)
        {
            int x=ar[r]*(r-l-1)-d[r-1]+d[l];
            if(x<=m)
            {
                ans=max(r-l,ans);
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
