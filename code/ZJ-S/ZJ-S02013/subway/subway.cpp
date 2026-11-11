#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,d,q,m;
long long walk[500010];
vector<pair<long,long> > v[500010];
vector<long long> vj[500010];
long long sat[500010],t[500010];
long long vis[500010];
int l,r;
void bfs(int x){
	queue<long long> q;
	q.push(x);
	vis[x]=0;
	while(!q.empty()){
		int nw=q.front();
		q.pop();
		for(int i=0;i<v[nw].size();i++){
			int nnw=v[nw][i].first,pi=v[nw][i].second;
			if(vis[nnw]>vis[nw]+pi){
				q.push(nnw);
				vis[nnw]=vis[nw]+pi;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>walk[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sat[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
			//	if(l==j) continue;
				v[sat[j]].push_back({sat[l],t[j]+t[l]});
				v[sat[l]].push_back({sat[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		memset(vis,0x3f3f,sizeof vis);
		bfs(i);
		for(int j=1;j<=m;j++){
			vj[i].push_back(vis[j]);
		}
	}
	while(q--){
		cin>>l>>r;
	//	ans=walk[l]+walk[r];
		cout<<walk[l]+walk[r]+vj[l][r-1]<<"\n";
	}
	return 0;
}