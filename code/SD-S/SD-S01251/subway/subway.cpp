#include<bits/stdc++.h>
using namespace std;
int h[600010],to[2000010],nxt[2000010],w[2000010],id;
long long f[510][510];
int td[1000010];
void add(int i,int j,int k){
	to[id]=j;
	nxt[id]=h[i];
	w[id]=k;
	h[i]=id++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&td[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			add(a,i+m,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=1e15;
			else f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=h[i];j!=-1;j=nxt[j]){
			for(int k=h[i];k!=-1;k=nxt[k]){
				f[to[j]-m][to[k]-m]=f[to[k]-m][to[j]-m]=min(f[to[j]-m][to[k]-m],w[j]+w[k]*1ll);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e15;
		for(int j=h[x];j!=-1;j=nxt[j]){
			for(int k=h[y];k!=-1;k=nxt[k]){
				ans=min(ans,f[to[j]-m][to[k]-m]+w[j]+w[k]+td[x]+td[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

