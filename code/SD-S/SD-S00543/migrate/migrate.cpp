#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 100;
template<typename TY>
void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	s = x * f;
}
int c,t;
int n;
ll a[N],d;
void solve(){
	ll ans = 0;
	read(n); read(d);
	vector<int> v;
	v.push_back(1);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(i > 1 && a[i] - a[i - 1] > d) v.push_back(i);
	}
	v.push_back(n);
	for(int i=0;i<v.size();i++){
		if(i - 1 >= 0 &&  v[i] - v[i - 1] + 1 >= 4) ans += v[i] - v[i - 1] - 2;
	}
	cout << ans << "\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c); read(t);
	while(t--) solve();
	return 0;
}
