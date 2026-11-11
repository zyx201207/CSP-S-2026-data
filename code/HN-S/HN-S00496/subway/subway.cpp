#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,k,u,v,w,w2,x,y,sum,vis[500005];
long long W[500005],a[500005],b[500005];
vector<int> ve[500005];
vector<int> wi[500005];

void bfs(long long o){
	queue<long long> q;
	q.push(o);
	while(q.size()!=0){
		u=q.front();
		q.pop();
		for(int i=0;i<ve[u].size();i++){
			v=ve[u][i];
			w=wi[u][i];
			if(vis[v]>vis[u]+w){
				vis[v]=vis[u]+w;
				q.push(v);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			a[j]=b[j]=0;
			cin>>a[j]>>b[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				ve[a[j]].push_back(a[l]);
				wi[a[j]].push_back(b[j]+b[l]);
				ve[a[l]].push_back(a[j]);
				wi[a[l]].push_back(b[j]+b[l]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			vis[i]=1e18;
		} 
		vis[x]=W[x];
		bfs(x);
		cout<<vis[y]+W[y]<<endl;
	}
	return 0;
} 
