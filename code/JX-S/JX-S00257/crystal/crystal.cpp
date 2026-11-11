#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
typedef long long ll;
ll n,m;
ll a[N];

bool check(int len)
{
    int l=1,r=len;
    while(r<=n)
    {
        if(a[r]-a[l]>m)return false;

        bool ok=true;
        ll cnt=0;

        for(int i=l; i<=r; i++)
        {
            cnt+=(a[r]-a[i]);
            if(cnt>m)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            return true;
        }
        l++,r++;
    }
    return false;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    ll diff=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    bool ok=true;
    diff=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=diff){
            ok=false;
            break;
        }
    }
    if(ok){
        ll num=0;
        for(int i=1;i<=n;i++){
            num+=i;
            if(diff*num>m){
                cout<<i<<'\n';
                return 0;
            }
        }
    }

    sort(a+1,a+1+n);
    int l=0,r=n+1;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l<<'\n';

    return 0;
}
