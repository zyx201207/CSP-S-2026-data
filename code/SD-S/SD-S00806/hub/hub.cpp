#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int min(int x,int y){
	return (x<y)?x:y;
}
int max(int x,int y){
	return (x>y)?x:y;
}
const int N=100+5,inf=1e18;
int n;
int C;
int m;
int fa[N];
vector<int>v[N];
int cnt[N][2][N],dep[N];
int dis[N][N];
bool bl[N][N][2];
void dfs(int x,int e,int opt){
	dep[x]=0;
	bl[x][e][opt]=1;
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		if(u==fa[x])continue;
		fa[u]=x;
		dfs(u,e,opt);
		dep[x]=max(dep[x],dep[u]+1);
	}
	cnt[e][opt][dep[x]]++;
}
void getdis(int x,int rt){
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		if(u==fa[x])continue;
		fa[u]=x;
		dis[u][rt]=dis[x][rt]+1;
		getdis(u,rt);
	}
}
pii e[N];
void clear(){
	for(int i=0;i<=n;i++){
		fa[i]=0;
		v[i].clear();
		dep[i]=0;
		for(int j=0;j<=n;j++)dis[i][j]=0,cnt[i][0][j]=cnt[i][1][j]=bl[i][j][0]=bl[i][j][1]=0;
	}
}
void sl(){
	clear();
	n=read(),m=read(); 
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
		e[i]={x,y};
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++)fa[j]=0;
		fa[e[i].fi]=e[i].se;
		dfs(e[i].fi,i,0);
		cnt[i][0][dep[e[i].fi]]--;
		for(int j=n-1;j>=0;j--)cnt[i][0][j]+=cnt[i][0][j+1];
		for(int j=0;j<=n;j++)fa[j]=0;
		fa[e[i].se]=e[i].fi;
		dfs(e[i].se,i,1);
		cnt[i][1][dep[e[i].se]]--;
		for(int j=n-1;j>=0;j--)cnt[i][1][j]+=cnt[i][1][j+1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)fa[j]=0;
		getdis(i,i);
	}
	int ans=inf;
	for(int i=1;i<n;i++){
		for(int opt1=0;opt1<=1;opt1++){
			for(int j=1;j<n;j++){
				for(int opt2=0;opt2<=1;opt2++){
					int x,y;
					if(opt1)x=e[i].se;
					else x=e[i].fi;
					if(opt2)y=e[j].se;
					else y=e[j].fi;
					if(bl[x][j][opt2]||bl[y][i][opt1])continue;
					int mx=0;
					for(int k=1;k<=n;k++){
						if(!bl[k][i][opt1]&&!bl[k][j][opt2]){
							mx=max(mx,min(dis[k][x],dis[k][y]));
						}
					}
					for(int k=mx;k<=n;k++){
						if(cnt[i][opt1][k]+cnt[j][opt2][k]+2<=m){
							ans=min(ans,k);
						}
					}
				}
			}
			int mx=0;
			for(int j=1;j<=n;j++){
				int x;
				if(opt1)x=e[i].se;
				else x=e[i].fi;
				if(!bl[j][i][opt1])mx=max(mx,dis[j][x]);
			}
			for(int j=mx;j<=n;j++){
				if(cnt[i][opt1][j]+1<=m){
					ans=min(ans,j);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
void slA(){
	n=read(),m=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
	}
	if(n==m){
		cout<<"0\n";
		return ;
	}
	if(m>=n/2){
		cout<<"1\n";
		return ;
	}
	n=n/2;
	int l=1,r=n,ans=n;
	while(l<=r){
		int len=n-mid-(mid+1)+1;
		len-=m;
		bool flag=0;
		if(len<=0)flag=1;
		else if((len+1)/2<=mid)flag=1;
		if(flag)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans+1<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();
	int t=1;
	t=read();
	if(C!=13&&C!=14)while(t--)sl();
	else while(t--)slA();
	return 0;
}
/*
额，就是你预处理每一种可能的子树，dis<=k需要多少，这个就是你考虑每个点是在他字树最大dep的时候放上的
所以预处理这个可以是 n^2
然后枚举哪两个子树，饿啊这个地方是不是还是要带个log
日啊感觉这些地方都是有点变态的
再想想吧
n^2 is too harddddd
难道我真的无法打到350？ 
不是 k=2我也不会n^2啊
和一位呢
日啊先把340写了稳一下厕所吧 
唉，没招了 
T4 蠕动2h+获得40分是和一位啊？？ 
唉，保守打法了，T1T3写完就上拍了，T4暴力和性质也拍了，检查一下T2 
*/

