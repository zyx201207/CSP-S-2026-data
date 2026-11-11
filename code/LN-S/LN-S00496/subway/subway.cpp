#include<bits/stdc++.h>
using namespace std;
/*vector<pair<node,int>>sub(500005);
struct node{
	int t,v;//t作为第i条线路的第t个点，到该线站台距离
	int too,fr;
};
long long lj(int q,int z,long long sum){
	if(q==z)return sum;
	long long bs=0x3f3f3f,nq;
	for(auto it : sub[x]){
		node awa=it.frist;
		if(awa.v<bs){bs=awa.v;nq=}
	}
}*/
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int w[500005];
	for(int i = 1;i<=m;++i)
	scanf("%d",&w[i]);
	int k[502],a,tt;
	for(int i = 1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j = 1;j<=k;++j){
			scanf("%d%d",&a,&tt);
			/*node awa;
			awa.t=j;
			awa.v=tt;
			sub[a].push_back({awa,i});*/
		}
	}int x,y;long long ans=0;
	while(q--){
		ans=0;
		scanf("%d%d",&x,&y);
		ans+=w[x];
		ans+=w[y];
		//ans+=lj(x,y,0);
		//printf("%lld",ans);
	}
	return 0;
}
