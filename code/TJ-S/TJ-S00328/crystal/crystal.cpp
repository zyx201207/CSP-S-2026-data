#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
//use ll!! qingkong!!! freopen!!!!
//rp++
const int N=5e5+10;
int n,m;
int a[N],d[N],s[N];

signed main()
{
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int ans = 1,sum = 0,cnt = 1;
    sort(a+1,a+n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        d[i] = a[i]-a[i-1];
        s[i] = d[i]+s[i-1];
    }
    for(int i = 2 ; i <= n ; i++)
    {
        cnt++;
        sum += d[i]*(cnt-1);
        while(sum > m)
        {
            cnt--;
            sum -= s[i]-s[i-cnt];
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}
