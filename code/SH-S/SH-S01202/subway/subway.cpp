#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int M=5e5+10; 

int c,n,m,d,q;
int w[M],k[M],ans=1e18;
vector<int> a[N],t[N];

bool flagA=1;
bool vis[M];
int h[M][30],g[M][30];

int cnt[M],sum[M],pay[M][5];

int read(){
	int f=1,K=0,C=getchar();
	for(;!isdigit(C);C=getchar())if(C=='-')f=-1;
	for(;isdigit(C);C=getchar())K=K*10+(C^48);
	return f*K;
}

void dfs(int x,int y,int cost){
//	cout<<x<<" "<<y<<" "<<cost<<endl;
	if(x==y){
		ans=min(ans,cost);
		return;
	}
	if(cost>=ans)return;
	for(int i=1;i<=h[x][0];i++){
		int to=h[x][i];
		int W=g[x][i];
		if(vis[to])continue;
		vis[to]=1;
		dfs(to,y,cost+W);
		vis[to]=0;
	}
	
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
//		scanf("%lld",&k[i]);
		k[i]=read();
		if(k[i]>2)flagA=0;
		for(int j=1;j<=k[i];j++){
			int aa,tt;
//			scanf("%lld%lld",&aa,&tt);
			aa=read();tt=read();
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	if(flagA){
		for(int i=1;i<=n;i++){
			if(k[i]==1)continue;
			g[a[i][0]][0]++;g[a[i][1]][0]++;
			if(g[a[i][0]][g[a[i][0]][0]]==0)g[a[i][0]][g[a[i][0]][0]]=1e18;
			if(g[a[i][1]][g[a[i][1]][0]]==0)g[a[i][1]][g[a[i][1]][0]]=1e18;
			g[a[i][0]][g[a[i][0]][0]]=min(g[a[i][0]][g[a[i][0]][0]],t[i][0]+t[i][1]);
			g[a[i][1]][g[a[i][1]][0]]=min(g[a[i][1]][g[a[i][1]][0]],t[i][0]+t[i][1]);
//			cout<<"*"<<a[i][1]<<" "<<a[i][0]<<endl;
			h[a[i][0]][0]++;h[a[i][1]][0]++;
			h[a[i][0]][g[a[i][0]][0]]=a[i][1];
			h[a[i][1]][g[a[i][1]][0]]=a[i][0];
		}
		/*
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(g[i][j]==1e18)continue;
				h[i].push_back(j);
				h[j].push_back(i);
//				cout<<"*"<<i<<" "<<j<<endl;
			}
		}
		*/
	}
	int minn=1e18;
	if(n<=2){
//		cout<<"*\n";
		for(int i=1;i<=2;i++){
			for(int j=0;j<k[i];j++){
				cnt[a[i][j]]+=i;
				sum[a[i][j]]+=t[i][j];
				pay[a[i][j]][i]=t[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]==3){
				minn=min(minn,sum[i]);
			}
		}
	}
	
	while(q--){
		int x,y;
		x=read();y=read();
//		scanf("%lld%lld",&x,&y);
		ans=1e18;
		if(flagA){
			memset(vis,0,sizeof(vis));
			vis[x]=1;
			dfs(x,y,0);
			printf("%lld\n",ans+w[x]+w[y]);
			continue;
		}
		if(n<=2){
//			cout<<"*\n";
			if(cnt[x]==1&&cnt[y]==1){
				ans=w[x]+w[y]+sum[x]+sum[y];
			}
			if(cnt[x]==1&&cnt[y]==3){
				ans=w[x]+w[y]+sum[x]+pay[y][1];
			}
			if(cnt[x]==2&&cnt[y]==2){
				ans=w[x]+w[y]+sum[x]+sum[y];
			}
			if(cnt[x]==2&&cnt[y]==3){
				ans=w[x]+w[y]+sum[x]+pay[y][2];
			}
			if(cnt[x]==3&&cnt[y]==1){
				ans=w[x]+w[y]+pay[x][1]+sum[y];
			}
			if(cnt[x]==3&&cnt[y]==2){
				ans=w[x]+w[y]+pay[x][2]+sum[y];
			}
			if(cnt[x]==1&&cnt[y]==2){
				ans=w[x]+w[y]+sum[x]+sum[y]+minn;
			}
			if(cnt[x]==2&&cnt[y]==1){
				ans=w[x]+w[y]+sum[x]+sum[y]+minn;
			}
			if(cnt[x]==3&&cnt[y]==3){
				ans=w[x]+w[y]+min(pay[x][1]+pay[y][1],pay[x][2]+pay[y][2]);
			}
			printf("%lld\n",ans);
			continue;
		}
		if(d<=2){
			
			
			
			
		}
		
		
	}
	
	
	return 0;
}
