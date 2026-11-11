#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M=1e6+10,N=510;
int w[M],d[M],zt[M];
vector<pii> a[M];
bool st[M];
map<pii,bool> mp;
void dij(int u,int k){
	memset(d,0x3f,sizeof(d));
	memset(st,false,sizeof(st));
	priority_queue<pii,vector<pii>,greater<pii> > q;
	d[u]=0;
	q.push({0,u});
	while(q.size()){
		pii t=q.top();q.pop();
		int tw=t.first,tv=t.second;
		if(tv==k) return;
		st[tv]=1;
		for(auto v:a[tv]){
			int vv=v.first,vw=v.second;
			if(st[vv]) continue;
			if(d[tv]+vw<d[vv]){
				d[vv]=d[tv]+vw;
				q.push({d[vv],vv});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,dm,q;
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int x;
			cin>>x;
			zt[j]=++cnt;
			for(int k=1;k<j;k++){
				if(mp[{zt[j],zt[k]}]) continue;
				a[zt[j]].push_back({zt[k],0});
				a[zt[k]].push_back({zt[j],0});
				mp[{zt[j],zt[k]}]=1;
				mp[{zt[k],zt[j]}]=1;
			}
			int ti;
			cin>>ti;
			a[x].push_back({zt[j],ti});
			a[zt[j]].push_back({x,ti});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
		cout<<w[x]+w[y]+d[y]<<endl;
	}

	return 0;
}

