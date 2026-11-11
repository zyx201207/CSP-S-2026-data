#include<bits/stdc++.h>
using namespace std;
const int N=7005;
long long w[N],dist[N][N],a[N][N],t[N][N],vis[N][N];
int c,n,m,d,q;
queue<int> sta; 
void dfs(int a){
	int cz;
	for(int i=1;i<=m;i++) if(dist[a][i]!=50005&&dist[a][i]!=0){
		sta.push(i);
		vis[a][i]=1;
		vis[i][a]=1;
		break;
	}
	while(!sta.empty()){
		cz=sta.front();
		//cout<<dist[2][4]<<vis[2][4]<<endl;
		sta.pop();
		for(int i=1;i<=m;i++){
			//cout<<i<<endl;
			if(dist[cz][i]!=0&&dist[cz][i]!=50005&&vis[cz][i]!=1){
			dist[a][i]=min(dist[a][i],dist[a][cz]+dist[cz][i]);
			dist[i][a]=dist[a][i];
			//cout<<cz<<i<<dist[a][i]<<endl;
			sta.push(i);
			vis[cz][i]=1;
			vis[i][cz]=1;
		}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dist[i][j]=50005;
	for(int i=1;i<=m;i++) dist[i][i]=0;
	for(int x=1;x<=n;x++){
		long long tm;
		cin>>tm;
		for(int x1=1;x1<=tm;x1++){
			cin>>a[x][x1];
			t[x][a[x][x1]]=99;
			//cout<<a[x][x1]<<t[x][a[x][x1]]<<endl;
			cin>>t[x][a[x][x1]]; 
			//cout<<a[x][x1]<<t[x][a[x][x1]]<<endl; 
		}
		for(int i=1;i<=tm;i++){
			for(int j=i+1;j<=tm;j++){
				long long b=a[x][i],c=a[x][j];
				//cout<<x<<b<<t[x][b]<<endl;
				dist[b][c]=min(t[x][b]+t[x][c],dist[b][c]);
				dist[c][b]=min(t[x][c]+t[x][b],dist[c][b]);
				//cout<<b<<c<<dist[b][c]<<endl; 
			}
		}
	}
	dfs(1);
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<dist[a][b]+w[a]+w[b]<<endl;
	}
	return 0;
} 
