#include<bits/stdc++.h>
using namespace std;
int m,c,n,d,q,x,y;
long long ans,g[500005];
struct site{
	int w,t[505];
	bool s[505];
}a[500005];
struct subway{
	bool p[500005];
}su[505];
void f(int x,int y,long long ti,int l){
	g[x]=ti;
	if(x==y){
		ans=min(ti+a[x].w,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x].s[i]){
			for(int j=1;j<=m;j++){
				if(su[i].p[j]){
					if(ti+a[j].t[i]+a[x].t[i]>=min(ans,g[j])||x==j||x==l)continue;
					f(j,y,ti+a[j].t[i]+a[x].t[i],x);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i].w);
	}
	int k,e;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&e);
			su[i].p[e]=1;
			a[e].s[i]=1;
			scanf("%d",&a[e].t[i]);
		}
	}
	while(q--){
		ans=10000000000000000;
		memset(g,0x3f,sizeof(g));
		scanf("%d%d",&x,&y);
		f(x,y,a[x].w,0);
		printf("%lld\n",ans);
	}
	return 0;
}