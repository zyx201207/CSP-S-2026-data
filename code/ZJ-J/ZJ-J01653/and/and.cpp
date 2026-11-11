#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
ll n, m, a, tj=-0x3f3f3f3f, d[101], pw[101];
int main(){
	//freopen("and.in", "-r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    pw[1] = 1;
    for(ll i=2;i<=32;i++){
        pw[i] = pw[i-1] * 2;
    }
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a;
        ll k = 1;
        while(a!=0){
            d[k] += a % 2;
            a /= 2;
            k++;
        }
        tj = max(tj, k);
    }
    ll ans = 0;
    for(ll i=tj;i>=1;i--){
        if (d[i] >= m){
            ans += pw[i];
        }
    }
    cout<<ans;
    return 0;
}
/*
5 3 31 1 3 15 7
*/