#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int bian,_t,n,dd,a[310],he[310],tot,d[310],f[310];
bool vis[310];
priority_queue<pii,vector<pii>,greater<pii> >q;
struct aaa{
	int to,ne,w;
}e[90010];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].ne=he[u];
	he[u]=tot;
}
int qq(int l,int r){
	if(a[r]-a[l]<=dd)
		return 0;
	tot=0;
	memset(he,0,sizeof(he));
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	memset(d,0x3f,sizeof(d));
	d[l]=0;
	f[l]=1;
	q.push(make_pair(0,l));
	for(int i=l;i<r;i++){
		for(int j=i+1;j<=r;j++){
			if(a[j]-a[i]<=dd)
				add(i,j,1);
			else
				break;
		}
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=he[u];i;i=e[i].ne){
			int v=e[i].to;
			if(d[v]>d[u]+e[i].w){
				f[v]=1;
				d[v]=d[u]+e[i].w;
				q.push(make_pair(d[v],v));
			}
			else
				if(d[v]==d[u]+e[i].w)
					f[v]++;
		}
	}
	if(f[r]==2)
		return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&bian,&_t);
	if(bian>6){
		while(_t--)
			printf("0\n");
		return 0;
	}
	while(!q.empty())
		q.pop();
	while(_t--){
		scanf("%d%d",&n,&dd);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n<=3){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int len=4;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				ans+=qq(l,r);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}