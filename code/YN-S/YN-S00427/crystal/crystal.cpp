#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int q[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--) a[i]-=a[i-1];
    int l=0,r=0,ans=1;
    ll mm=0,tot=0;
    for(int i=2;i<=n;i++)
    {
        q[++r]=i;
        tot+=a[i];
        mm+=(r-l)*a[i];
        while(l<r && mm>m)
        {
            mm-=tot;
            tot-=a[q[l+1]];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
