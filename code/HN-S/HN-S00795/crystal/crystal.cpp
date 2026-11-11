#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
inline void MAX(auto &x,auto y){x=max(x,y);}
inline void MIN(auto &x,auto y){x=min(x,y);}
const int N=5e5+5;
int n;
ll m,a[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        while(a[i]*(i-j+1)-s[i]+s[j-1]>m)
            j++;
        MAX(ans,i-j+1);
    }
    cout<<ans<<'\n';
    return 0;
}