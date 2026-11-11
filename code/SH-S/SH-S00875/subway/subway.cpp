#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define getchar_unlocked() getchar()
inline int read(){
	int x=0;char c=getchar_unlocked();
	while(c>'9' or c<'0')c=getchar_unlocked();
	while(c<='9' and c>='0')
		x=x*10+(c-'0'),c=getchar_unlocked();
	return x;
}
int c,n,m,dd,q; 
int gs[555][555];//地铁之间换乘的最短距离，用来跑floyd 

//unordered_set<int>s[555];//每个站点过哪几条地铁，方便查找 
int sz[555];//每条地铁过几个站点

int w[505050];//站厅 和 地铁口 的 距离，最后才用到 

vector<int>g[505050],d[505050];
//g表示能走到哪几条地铁，d是对应的用时

void floyd(int a[555][555],int sn){
	for(int k = 1;k<=sn;k++)
		for(int i = 1;i<=sn;i++)
			for(int j = 1;j<=sn;j++)
				gs[i][j]=min(gs[i][j],gs[i][k]+gs[k][j]);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),dd=read(),q=read();
	for(int i = 1;i<=m;i++)w[i]=read();
	for(int i = 1;i<=n;i++){
		sz[i]=read();int zhan,tim;
		for(int j = 1;j<=sz[i];j++){
			zhan=read();tim=read();
			
			g[zhan].push_back(i);
			d[zhan].push_back(tim);
			
			//s[zhan].insert(i); 
		}
	}
	memset(gs,63,sizeof(gs));
	for(int i = 1;i<=n;i++)gs[i][i]=0;
	//cerr<<"OK1\n";
	for(int i = 1;i<=m;i++){//对于每个换乘点，向地铁之间建边 
		for(int j = 0;j<g[i].size()-1;j++){
			int u=g[i][j];
			for(int k = j+1;k<g[i].size();k++){
				int v=g[i][k]; 
				gs[u][v]=gs[v][u]=min(gs[u][v],d[i][j]+d[i][k]); 
			}
		}
	}
	
	/*
	
	
	cout<<"地铁之间的直接换乘结果:\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(gs[i][j]>=1e18)cout<<"-1 ";
			else cout<<gs[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\n\n地铁之间的间接换乘结果:\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(gs[i][j]>=1e18)cout<<"-1 ";
			else cout<<gs[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	*/
	
	floyd(gs,n);
	//cerr<<"OK2\n";
	while(q--){
		int x=read(),y=read();
		int ans=1e18;
		//cout<<"OK!\n";
		for(int i = 0;i<g[x].size();i++)
			for(int j = 0;j<g[y].size();j++){//枚举刚开始和结束时坐哪两条地铁 
				int u=g[x][i],v=g[y][j];
				ans=min(ans,d[x][i]+d[y][j]+gs[u][v]); 
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} 
