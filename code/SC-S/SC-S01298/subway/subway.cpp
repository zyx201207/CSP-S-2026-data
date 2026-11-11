#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],k[510],t[510][N];
long long dis[N];
int vis[510];
vector <int> sta[N],a[510];
void find(int x,int y,long long tt){
	if(dis[x]<=tt){
		return;
	}else{
		dis[x]=tt;
	}
	
	for(int i=0;i<sta[x].size();i++){
		int s=sta[x][i];
//		if(vis[s]) continue;
		long long t3=1;
		for(int j=1;j<=k[s];j++){
			find(a[s][j],y,tt+t3*t[s][x]+t3*t[s][a[s][j]]);
		}
//		vis[s]=1;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			cin>>t1>>t2;
			a[i].push_back(t1),t[i][t1]=t2;
			sta[t1].push_back(i);
		}
	}
//	cout<<t[1][1]+t[1][a[0][2]];
	for(int i=1;i<=q;i++){
		memset(dis,0x3f,sizeof dis);
		int x,y;
		cin>>x>>y;
		long long t1=0;
		find(x,y,t1);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}