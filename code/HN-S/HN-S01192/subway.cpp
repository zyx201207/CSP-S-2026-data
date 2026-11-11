#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
const int N=505; 
int w[M];ll dist[N][N];
vector< pair<int,int> >e[M];
char in[(1<<21)+5],*p1=in,*p2=in;
#define getchar() p1==p2&&(p2=in+fread(p1=in,1,1<<21,stdin),p1==p2)?EOF:*p1++
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		while(k--){
			int a=read(),t=read();
			e[a].push_back({t,i});
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			for(int k=j+1;k<(int)e[i].size();k++){
				dist[e[i][j].second][e[i][k].second]=min(dist[e[i][j].second][e[i][k].second],1ll*(e[i][j].first+e[i][k].first));
				dist[e[i][k].second][e[i][j].second]=min(dist[e[i][k].second][e[i][j].second],1ll*(e[i][j].first+e[i][k].first));
			}
		}
	}
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		x=read(),y=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<(int)e[x].size();i++){
			for(int j=0;j<(int)e[y].size();j++){
				ans=min(ans,dist[e[x][i].second][e[y][j].second]+e[x][i].first+e[y][j].first);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
