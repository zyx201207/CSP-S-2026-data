#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll a[N];
ll n,m,maxlen = -1;
ll myabs(ll x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    ll l = 1,r = 1,s = 0;
    while(r <= n){
        if(s <= m){
            maxlen = max(maxlen,r - l + 1);
            r++;
            s += myabs(a[r] - a[r - 1]) * (r - l);
        } 
        else{
        	l++;
        	s -= myabs(a[r] - a[l - 1]);
		}
    }
    cout << maxlen;
    return 0;
}