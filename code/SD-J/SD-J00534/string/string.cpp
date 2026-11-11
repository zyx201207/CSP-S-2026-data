#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define all(u) (u).begin(),(u).end()
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 1000005

using namespace std;
int n,m;
int a[N];
char b[N];
string s;
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
//	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++) {
		cin>>a[i]>>b[i];
		for(int j = 1;j <= a[i];j ++) s += b[i];
	}
	auto t = s;reverse(all(t));
	int ans = 0,m = t.size();
	for(int i = 0;i < (m + 1) / 2;i ++) {
		ans += (s[i] != t[i]);
	}
	cout<<ans<<"\n";
//	int ans = m,i = 1,j = n,L = 0,R = 0;
//	while(i <= n || j >= 1) {
//		while(i <= n && L <= R) {
//			L += a[i],i ++;
//			if(b[i] == b[j]) ans -= abs(L - R);
//			cout<<i<<" "<<j<<" "<<L<<" "<<R<<"\n";
//		}
//		while(j >= 1 && R <= L) {
//			R += a[j],j --;
//			if(b[i] == b[j]) ans -= abs(L - R);
//			cout<<i<<" "<<j<<" "<<L<<" "<<R<<"\n";
//		}
//	}
//	cout<<ans<<"\n";
	return 0;
}

