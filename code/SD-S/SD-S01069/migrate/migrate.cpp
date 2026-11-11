#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int miN = 5e3 + 10; 
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,d,a[N],mi=INF,cnt=0;
void dfs(int x,int en,int ans) {
	if(ans>mi) return;
	if(x==en) {
		if(ans<mi) {
			cnt=1;
			mi=ans;
		}
		else cnt++;
		return;
	}
	for(int i=x+1;i<=en;i++) {
		if(a[i]-a[x]<=d) dfs(i,en,ans+1);
	}
}
void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=300) {
		ll num=0;
		for(int i=2;i<=n;i++) {
			for(int j=1;j+i-1<=n;j++) {
				mi=INF,cnt=0;
				dfs(j,j+i-1,0);
				if(cnt==2) num++;
			}
		}
		cout<<num<<'\n';
	}
	else {
		cout<<0<<'\n';
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}

