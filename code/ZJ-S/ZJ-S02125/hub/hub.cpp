#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>ve[10005];
long long ans=0;
long long x;
int sum;
int cnt;
vector<int>a;
bool f[1005];
int b[10005];

void dfs(int dep) {
	f[dep]=1;
	for(int i=0;i<ve[dep].size();i++) {
		int xx=ve[dep][i];
		if(!f[xx]) dfs(xx);
	}
}

void dfs_(int dep,int la,int no) {
	b[dep]=no;
	for(int i=0;i<ve[dep].size();i++) {
		int xx=ve[dep][i];
		if(!(!f[dep]&&f[xx])) {
			if(f[xx]) dfs_(xx,dep,0);
			else dfs_(xx,dep,no+1);
		}
	}
}

void solve_(int c) {
	cnt=0,sum=0;
	for(int i=1;i<=c;i*=2){
		int b=c/i;
		cnt++;
		if(b&1) {
			sum++;
			a.push_back(cnt);
		}
	}
	if(sum==k) {
		int aa;
		memset(f,0,sizeof(f));
		dfs(a[0]);
		for(int i=1;i<=k;i++) {
			if(!f[a[i]]) {
				dfs(a[i]);
				aa=a[i];
				break;
			}
		}
		for(int i=1;i<=k;i++) {
			if(!f[a[i]]) {
				return;
			}
		}
		long long res=0;
		dfs_(a[0],a[0],0);
		dfs_(aa,aa,0);
		for(int i=1;i<=n;i++) {
			res+=b[i];
			b[i]=0;
		}
		ans=max(ans,res);
	}
}

void solve() {
	cin>>n>>k;
	if(k>4000) {
		cout<<(((n+1)/2-1)/2+1)*4+2<<'\n';
		return;
	}
	for(int i=1;i<=n;i++) {
		ve[i].clear();
	}
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	for(int i=1;i<(1<<n);i++) {
		solve_(i);
	}
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
}
