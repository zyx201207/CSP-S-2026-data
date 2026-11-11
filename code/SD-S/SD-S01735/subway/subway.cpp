#include<bits/stdc++.h>
using namespace std;
const int N=510,M=2e4+10;
long long d[M],c,n,m,dd,Q,a[M],nm;
long long sss[1005][1005],ans;
bool v[M];
struct dian{
	long long t,s;
	friend bool operator <(dian x,dian y){
		return x.s>y.s;
	}
};
struct node{
	int v,w;
};
vector <node> g[M+N];
void dijs(int st,int e){
	for(int i=1;i<=nm;i++) d[i]=1e18,v[i]=0;
	d[st]=0;
	priority_queue <dian> q;
	q.push({st,0});
	while(!q.empty()){
		long long u=q.top().t,s=q.top().s;
		q.pop();
		if(v[u]){
			if(u==e){
				ans=s;
				return;
			}
			continue;
		} 
		v[u]=1;
		int sz=g[u].size();
		for(int i=0;i<sz;i++){
			long long x=g[u][i].v,w=g[u][i].w;
			if(!v[x]&&d[x]>s+w){
				d[x]=s+w;
				q.push({x,d[x]});
			}
		}
	}
	if(c<=11&&c>=9){
		for(int i=1;i<=m;i++){
			sss[st][i]=d[i];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>Q;
	nm=n+m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int aa,tt;
			cin>>aa>>tt;
			g[aa].push_back({m+i,tt});
			g[m+i].push_back({aa,tt});
		}
	}
	if(c<=11&&c>=9){
		for(int i=1;i<=m;i++){
			dijs(i,-1);
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<sss[x][y]+a[x]+a[y]<<"\n";
		}
		return 0;
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ans=-1;
		dijs(x,y);
		if(ans!=-1) cout<<ans+a[x]+a[y]<<"\n";
		else cout<<d[y]+a[x]+a[y]<<"\n";
	}
	return 0;
}
