#include<bits/stdc++.h>
using namespace std;
const int M=500010;
const int N=510;

int c,n,m,d,t,w[M];
int k,xr,yr;

vector<pair<int,int> > s[M+N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			s[x].push_back({m+i,y});
			s[m+i].push_back({x,y});
		}
	}
	while(t--){
		cin>>xr>>yr;
		queue<int> q;
		int dis[M+N];
		dis[xr]=0;
		q.push(xr);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(yr==u)
				break;
			for(auto v:s[u]){
				if(dis[v.first]==0){
					dis[v.first]=dis[u]+v.second;
					q.push(v.first);
				}
			}
		}
		cout<<dis[yr]+w[xr]+w[yr]<<'\n';
	}
	return 0;
}
