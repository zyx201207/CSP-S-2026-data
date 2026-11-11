#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c;
ll read(){
	ll f=1,a=0;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return f*a;
}
int n;
#define pii pair<int,int>
#define deep first
#define ver second
vector<vector<bool>> md;
int bfs(int u){
	queue<pii> q;
	vector<int> d(n,INT_MAX>>1),go(n);
	q.push({0,u});
	d[u]=0;
	while(q.size()){
		pii k=q.front();q.pop();
		if(d[k.ver]==k.deep) go[k.ver]++;
		for(int v=k.ver+1;v<n;v++)
			if(md[k.ver][v]){
				q.push({k.deep+1,v});
				d[v]=min(d[v],d[k.ver]+1);
			}
	} 
	int cnt=0;
	for(int i:go) cnt+=i==2;
	return cnt;
}
void solve(){
	md.clear();
	ll d;
	n=read();d=read();
	vector<ll> a(n);
	md.resize(n,vector<bool>(n));
	for(ll &i:a) i=read();
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			md[i][j]=(a[j]-a[i])<=d;
	int ans=0;
	for(int i=0;i<n;i++) ans+=bfs(i);
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	read();t=read();
	while(t--) solve();
}