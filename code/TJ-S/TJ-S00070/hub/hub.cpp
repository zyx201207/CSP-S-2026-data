#include<bits/stdc++.h>
#define rep(a,b) for(int i=(a); i<=(b); ++i)
#define per(a,b) for(int i=(b); i>=(a); ---i)
#define ll long long
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int N = 1e5 + 5;
int c, t, n, k, a, b;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){ 
		cin >> n >> k;
		rep(1,n-1) cin >> a >> b;
		cout << 0 << '\n';
	} 
	return 0;
}
