#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
#define off ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fi first
#define se second
using namespace std;
const int N=500005;
int n,m,a[N],pre[N];
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        int cnt=pre[i]-pre[i-x];
        if(a[i]*x-cnt<=m)
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    off;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }
    int L=1,R=n+1;
    while(L+1<R)
    {
        int mid=L+R>>1;
        if(check(mid))
        {
            L=mid;
        }
        else
        {
            R=mid;
        }
    }
    cout<<L;
    return 0;
}
//file memory long long
