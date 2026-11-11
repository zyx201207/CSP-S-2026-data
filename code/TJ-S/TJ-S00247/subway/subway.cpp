#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500005],a[500005],t[500005],x[100005],y[100005];
int k[505];
int main(){
	//mol Gzy mol wb
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[j],&t[j]);
	}
	for(int i=1;i<=q;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=q;i++){
		ans=0;
		ans+=w[x[i]];
		ans+=w[y[i]];
		printf("%d\n",ans);
	}
	return 0;
}
