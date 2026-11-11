#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int pre[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
        pre[i]=pre[i+1]+a[i];
    int cur=m;
    int l=n;
    int ans=0;
    a[0]=1e18;
    for(int r=n;r>=1;r--)
    {
        if(r<n){
            cur=cur+((r+1-l+1)*a[r+1]-(pre[l]-pre[r+2]))-((r-l+1)*a[r]-(pre[l]-pre[r+1]));
        }
        if(l>r) l=r;
        while(l>1&&(cur-(a[r]-a[l-1])>=0)) 
        {
            l--;            
            cur-=(a[r]-a[l]);
        };
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}