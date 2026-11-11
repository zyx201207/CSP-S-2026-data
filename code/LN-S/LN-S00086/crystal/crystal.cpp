#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
const int maxn = 5e5+10;

ll n,m,q;
ll a[maxn];
ll sum[maxn];
ll ans=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    bool flag=true;
    q=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=q) flag=false;
    }
    if(flag)
    {
        sum[1]=q;
        for(int i=2;i<=n-1;i++)
        {
            sum[i]=sum[i-1]+q;
            if(sum[i]==m)
            {
                cout << i;
                return 0;
            }
            if(sum[i]>m)
            {
                cout << i-1;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);

    for(int i=n;i>=2;i--)
    {
        ll cnt=0,jsq=0;
        for(int j=i-1;j>=1;j--)
        {
            if(jsq+abs(a[i]-a[j])>m) break;
            jsq+=abs(a[i]-a[j]);
            cnt++;
        }
        ans=max(cnt,ans);
    }

    cout << ans+1;

    return 0;
}
/*
2023/8/23-2026/10/31
Aetherius AFO
cout << "Bye World!";
Q.E.D
return 0;
*/
