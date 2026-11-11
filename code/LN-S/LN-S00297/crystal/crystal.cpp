#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
const int N=5e5+5;
int a[N];
int pre[N];



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }

    int l=1,r=n;
    int ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;

        int cur=1e18+1;
        for(int i=mid;i<=n;i++)
        {
            int w=mid*a[i]-(pre[i]-pre[i-mid-1]);
            cur=min(cur,w);
        }

        if(cur<=m)
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;


    return 0;
}