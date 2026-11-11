#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int inf = 1e18;
const int N = 2e5+5;
int a[N];
void read(int &x){
	char c = getchar();
	while(c!='-'&&!(c>='0'&&c<='9'))c=getchar();
	int f = 1;
	if(c=='-')f = -1;
	x = 0;
	while((c>='0'&&c<='9')){
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
void solve(){
	int n,m;
	read(n);
	read(m);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		read(a[i]);
	}
	for(int i = 30;i >= 0;i--){
		//1ll<<k;
		ans |= (1ll<<i);
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			cnt += ((ans&a[j])==ans);
		}
		if(cnt < m){
			ans ^= (1ll<<i);
		}
	}
	cout << ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _ = 1;
//	scanf("%lld",&_);
	while(_--)solve();
	return 0;
}
