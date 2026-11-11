#include<bits/stdc++.h>
#define N 500005
#define ll long long
#define mod 
using namespace std;

int n;
ll m,a[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll cur=0;
    int ans=1,l=1;
    for(int i=2;i<=n;i++)
    {
        cur+=1ll*(a[i]-a[i-1])*(i-l);
        while(l<i&&cur>m) cur-=a[i]-a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
// Code by Jorisy, after retiring. Just enjoy it.
// 1st time to pass all examples in t1 in 5 min