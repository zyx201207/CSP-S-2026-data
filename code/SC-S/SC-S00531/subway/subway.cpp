#include<bits/stdc++.h>
using namespace std;
int c,n,m,gg,q;
int w[500005];
vector<pair<int,int> > v[505];
int vis[500005];
long long d[500005];
int cnt[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>gg>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a,t;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[m+i].push_back({a,t});
			v[a].push_back({m+i,t});
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		queue<int> q;
		memset(d,0X3f,sizeof(d));
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		vis[x]=1;
		d[x]=0;
		q.push(x);
		while(q.size()){
			int f=q.front();
			//cout<<f<<' ';
			cnt[f]++;
			if(cnt[f]>=gg) continue;
			q.pop();
			d[f]+=w[f];
			for(auto i:v[f]){
				int ne=i.first,we=i.second;
				if(d[ne]>d[f]+we+w[ne]&&vis[ne]!=1){
					d[ne]=d[f]+we;
					q.push(ne);
					//if(ne<=m) vis[ne]=1;
				}
			}
		}
		cout<<d[y]<<'\n';
	}
	return 0;
} 