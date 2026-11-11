#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=505010;
priority_queue<pii,vector<pii>,greater<pii> >q;
int e[3010][3010];
int c,n,m,d,T;
int vis[N];
int k[N];
int a[N],t[N];
int w[N];
vector<int> ed[N];
int dis[N];
int que[N];
int fi=1,ta=0;
int ans[N];
int x[100010];
int y[100100];
void solve(int x){
	int u=x+m;
	vis[u]=1;
	que[++ta]=u;
	dis[u]=0;
	while(fi<=ta){
		int now=que[fi];
//		printf("now=%lld ",now);
		fi++;
		for(int i=0;i<ed[now].size();i++){
//			printf("i=%lld ",i);
			if(!vis[ed[now][i]]){
				que[++ta]=ed[now][i];
				vis[ed[now][i]]=1;
				dis[ed[now][i]]=min(dis[ed[now][i]],dis[now]+1);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
	if(c<=11){//floyd
		for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)
				e[i][j]=0;
				else
				e[i][j]=LLONG_MAX/3;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&a[j],&t[j]);
			for(int j=1;j<=k[i]-1;j++){
				for(int l=j+1;l<=k[i];l++){
					e[a[j]][a[l]]=t[l]+t[j];
					e[a[l]][a[j]]=t[l]+t[j];
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(e[i][j]>e[i][k]+e[k][j]){
						e[i][j]=e[i][k]+e[k][j];
					}
				}
			}
		}
		for(int i=1;i<=T;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",e[x][y]+w[x]+w[y]);
		}
	}
	else if(c<=19){
		for(int i=1;i<=T;i++)
		ans[i]=LLONG_MAX;
		for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
		int TTT=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&a[j],&t[j]),TTT=t[j];
			for(int j=1;j<=k[i];j++){
				ed[m+i].push_back(a[j]);
				ed[a[j]].push_back(m+i);
			}
		}
		for(int i=1;i<=T;i++)
		scanf("%lld%lld",&x[i],&y[i]);
		for(int i=1;i<=n;i++){
			fi=1,ta=0;
			solve(i);//对每一个汇点求最短路 
			for(int j=1;j<=T;j++){
				if(dis[x[j]]==INT_MAX || dis[y[i]]==INT_MAX)
				continue;
				ans[j]=min(ans[j],(dis[x[j]]+dis[y[j]])*TTT+w[x[j]]+w[y[j]]);
			}
			for(int j=1;j<=n+m;j++)
			vis[j]=0;
			for(int j=1;j<=n+m;j++)
			dis[j]=INT_MAX;
		}
		for(int i=1;i<=T;i++)
		printf("%lld\n",ans[i]);
	}
	return 0;
}
