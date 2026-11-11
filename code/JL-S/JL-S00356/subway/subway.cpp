#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,long long> pil;
#define f first
#define s second
const int N=5e5+10;
const ll inf=1e18;
int c,m,n,d,q,num[505],cnt[N];
ll w[N],dist[505][505];
pil a[N][21];
vector<pil> l[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];j++){
			int t1;ll t2;
			scanf("%d%lld",&t1,&t2);
			l[i].push_back({t1,t2});
			a[t1][++cnt[t1]].f=i;
			a[t1][cnt[t1]].s=t2;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dist[i][j]=inf;
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<num[i];j++){
			ll val=l[i][j].s;
			for(int k=1;k<=cnt[l[i][j].f];k++){
				int ex=a[l[i][j].f][k].f;
				ll len=a[l[i][j].f][k].s;
				if(ex==i) continue;
				dist[i][ex]=min(dist[ex][i],len+val);
				dist[ex][i]=dist[i][ex];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll temp=w[x]+w[y],ans=inf;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,temp+a[x][i].s+a[y][j].s+dist[a[x][i].f][a[y][j].f]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
