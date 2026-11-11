#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2*1e5+5;
ll n,m;
ll a[MAXN];
ll num,ans;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]==2) num++;
        if(a[i]==3) ans++;
    }
    cout<<n<<" "<<num<<" "<<ans;
    return 0;
}
