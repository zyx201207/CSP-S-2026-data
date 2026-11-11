#include<bits/stdc++.h>
using namespace std;
map<int,int> mp[50050];
long long c,n,m,d,q,x,y;
long long w[5050],t[550][50050],k[550],tw[550][50050];
long long wi[5050][5050];
map<long long,bool> ve[50050];
long long dist[5050][5050];
void bfs(){
	dist[x][x]=0;
	queue<long long> qu;
	qu.push(x);
	while(qu.size()){
		long long d=qu.front();
		for(long long i=1;i<=m;i++){
			if(d!=i&&ve[d][i]==1){
				long long f=wi[d][i];
				if(dist[d][x]+f<dist[i][x]){
					dist[i][x]=dist[d][x]+f;
					qu.push(i);
				}	
			}
		}
		qu.pop();
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(wi,0x3f,sizeof(wi));
	memset(dist,0x3f,sizeof(dist));	
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>t[i][j]>>tw[i][j];
			for(long long l=1;l<=j-1;l++){
				ve[t[i][j]][t[i][l]]=1;
				ve[t[i][l]][t[i][j]]=1;
				wi[t[i][j]][t[i][l]]=min(wi[t[i][j]][t[i][l]],tw[i][j]+tw[i][l]);
				wi[t[i][l]][t[i][j]]=min(wi[t[i][l]][t[i][j]],tw[i][j]+tw[i][l]);
			}	
		}
	}
	for(long long i=1;i<=m;i++){
		x=i;
		bfs();
	}
	while(q--){
		cin>>x>>y;
		cout<<dist[y][x]+w[y]+w[x]<<endl;
	}
	return 0;
}
