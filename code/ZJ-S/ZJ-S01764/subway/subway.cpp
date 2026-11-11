#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5e5+10,MAXN=510,INF=1e18;
vector<pair<int,int> >pass[MAXM];
int w[MAXM],road[MAXN][MAXN];
int c,n,m,d,q,k,a,t;
int read(){
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	//c：测试点编号
	//n：地铁线路数
	//m：地铁站数
	//d：每条地铁最多经过地铁站数 
	//q：计划数
	for(int i=1;i<=m;i++){
//		cin>>w[i];//口 到 站厅 
		w[i]=read();
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)road[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t;
			for(int l=0;l<pass[a].size();l++){
				int x=pass[a][l].first,tt=pass[a][l].second;
				if(road[i][x]>t+tt){
					road[i][x]=road[x][i]=t+tt;
				}
			}
			pass[a].push_back({i,t});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(road[i][k]+road[k][j]<road[i][j]){
					road[i][j]=road[i][k]+road[k][j];
				}
			}
		}
	}
	
	int xl,xr;
	for(int i=1;i<=q;i++){
		cin>>xl>>xr;
		int ans=INF;
		for(int j=0;j<pass[xl].size();j++){
			int st=pass[xl][j].first,stlen=pass[xl][j].second;
			for(int k=0;k<pass[xr].size();k++){
				int ed=pass[xr][k].first,edlen=pass[xr][k].second;
				ans=min(ans,road[st][ed]+stlen+edlen);
			}
		}
		cout<<ans+w[xl]+w[xr]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

out:
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3

out:
35
17
*/
