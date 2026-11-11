#include<bits/stdc++.h>
using namespace std;

int n,d;
map<int,int>x,to;
long long ans=0;
int aaa;
int cnt;

void dfs(int now,int dep) {
	if(dep==cnt&&now!=aaa) return;
	for(int i=now+1;i<=to[now];i++)
}

void solve() {
	cin >> n >> d;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;x[j]-x[i]<=d;j++) {
			to[i]=j;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			aaa=j;
			int a=i;
			cnt=0;
			while(a<j) {
				cnt++;
				a=to[a];
			}
		}
	}
	cout<<ans<<'\n';
}

int main() {
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}
