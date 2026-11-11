#include <bits/stdc++.h> // 13min cwz 14:30 - 14:43
#define ll long long
using namespace std;

const int N=5e5+5;
int n,m,ans;
ll a[N],pre[N];

bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        ll tmp=pre[i]-pre[i-x];
        ll cost=a[i]*x;
        if(cost-tmp<=m) return 1;
    }
    return 0;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int L=1,R=n;
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if(check(mid)) ans=mid,L=mid+1;
        else R=mid-1;
    }
    cout<<ans;
    return 0;
}
