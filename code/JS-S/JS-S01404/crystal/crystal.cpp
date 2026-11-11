#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,m,sum;
ll a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);
    ll k=0;
    ll w=n-1;
    a[n+1]=a[n];
    for(int i=1;i<=n;i++)
    {
        ll x=a[i+1]-a[i];
        sum+=x;
        k+=x*w;
        w-=1;
    }
    ll d=1e18;
    for(int i=n;i>=1;i--)
    {
        if(d==1e18)
            d=k;
        else
            d=d-sum;
        if(m>=d)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}
