#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1;
    int sumr=0,suml=0,maxn=0;
    for(int r=1;r<=n;r++)
    {
        sumr+=a[r];
        while(l+1LL<=r and (r-l+1LL)*a[r]-(sumr-suml)>m)
        {
            l++;
            suml+=a[l-1];
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
}
