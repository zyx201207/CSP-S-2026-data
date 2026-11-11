#include<bits/stdc++.h>
using namespace std;
long long c,n,m,dd,Q,w[500005],k,d[505][505],e[505][505];
struct sh{
	long long go,vv;
};
vector<sh> v[500005];
queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				d[i][j]=9e17;
				e[i][j]=9e17;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int l=v[i].size()-1;
		for(int j=0;j<=l;j++){
			for(int kk=j+1;kk<=l;kk++){
				e[v[i][j].go][v[i][kk].go]=min(e[v[i][j].go][v[i][kk].go],v[i][j].vv+v[i][kk].vv);
				e[v[i][kk].go][v[i][j].go]=min(e[v[i][kk].go][v[i][j].go],v[i][j].vv+v[i][kk].vv);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		q.push(i);
		while(!q.empty()){
			long long x=q.front();
			q.pop();
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][x]+e[x][j]){
					d[i][j]=d[i][x]+e[x][j];
					q.push(j);
				}
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		long long ans=9e17;
		int lx=v[x].size()-1;
		int ly=v[y].size()-1;
		for(int i=0;i<=lx;i++){
			for(int j=0;j<=ly;j++){
				ans=min(ans,v[y][j].vv+v[x][i].vv+d[v[x][i].go][v[y][j].go]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

