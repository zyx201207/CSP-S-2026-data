#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T,ans,w[500001],t[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&T);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		int k;
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				int h,x;
				scanf("%d %d",&h,&x);
				t[h]+=x;
			} 
		}
	while(T--){
		ans=0;
		int u,v;
		scanf("%d %d",&u,&v);
		for(int i=u;i<=v;i++){
			ans+=t[i];
		}
		printf("%d",ans+w[u]+w[v]);
	}
	return 0;
}

