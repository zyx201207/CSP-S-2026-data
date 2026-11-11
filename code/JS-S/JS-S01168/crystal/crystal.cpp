#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define mp make_pair
#define ll long long
#define pii pr<int,int>
using namespace std;
ll a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int cl=0;
    ll cs=0;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        cs+=(i-cl)*(a[i]-a[i-1]);
        while(cs>m) cs-=a[i]-a[cl++];
        ans=max(ans,i-cl+1);
    }
    cout<<ans<<endl;
    return 0;
}
