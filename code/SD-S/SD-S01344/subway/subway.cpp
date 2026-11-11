#include<bits/stdc++.h>
#include<queue>
#define int long long
using namespace std;
const int N=5e5+10,M=998244353;

int c,n,m,d,qu,w[N],f[1010][1010],zh[N][2],ans[1010][1010];
bitset<1010> b;
vector<pair<int,int> > e[1010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

void dij(int s){
	b.reset();
	q.push(make_pair(0,s));
	while(!q.empty()){
		int d=q.top().first,x=q.top().second;
		q.pop();
		if(b[x])continue;
		b.set(x);
		ans[s][x]=d;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i].first,z=e[x][i].second;
			if(b[y])continue;
			if(d+z<ans[s][y]){
				ans[s][y]=d+z;
				q.push(make_pair(d+z,y));
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>qu;
    
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=f[i][j]=1008600100860010086;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>zh[j][0]>>zh[j][1];
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				int x=zh[j][0],y=zh[k][0];
				f[x][y]=min(f[x][y],zh[j][1]+zh[k][1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==1008600100860010086)continue;
			e[i].push_back(make_pair(j,f[i][j]));
		}
	}
	if(n>1000&&qu<=2000){
		while(qu--){
			int x,y;
			cin>>x>>y;
			dij(x);
			cout<<ans[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
/*	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==1008600100860010086)cout<<-1;
			else cout<<f[i][j];
			cout<<" \n"[j==m];
		}
		cout<<ans[1][i]<<'\n';
	}*/
	while(qu--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<'\n';
	}
    
	return 0;
}


