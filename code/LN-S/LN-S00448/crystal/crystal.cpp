#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;

ll a[N],b[N];
ll n,m,mx,fff=0;

ll fi(ll s,ll l)
{
    int t = l;
    while(1)
    {
        ll mid = (l+s)>>1;
        ll md = (t-mid+1)*mx - b[t] +b[mid-1];

        //cout<<mx<<"--"<<b[t]<<"--"<<b[mid-1]<<"\n";

        //cout<<"--"<<s<<"--"<<l<<"--"<<mid<<"=="<<md<<"\n";

        if(md>m) s = mid;
        else if(md<m) l = mid;
        else
        {
            fff = 1;
            return mid;

        }
        if(mid == ((l+s)>>1)) return mid;

    }



}




int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>m;

    for(ll i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    stable_sort(a+1ll,a+1ll+n);
    mx = a[n];
    ll cc = 0;
    for(ll i = 1;i<=n;i++)
    {
        b[i] = b[i-1]+a[i];
        cc+=mx - a[i];
    }
    if(m>=cc)
    {
        cout<<n;
        return 0;
    }
    ll ans = 0;

    for(ll i = n;i>=1;i--)
    {
        mx = a[i];
        ll ff = fi(1,i);
        //cout<<ff<<"---\n";
        if(ans<i-ff+fff)
        {
            ans = i-ff+fff;

        }
        fff = 0;



    }

    cout<<ans;

    return 0;
}
