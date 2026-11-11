#include<bits/stdc++.h>
using namespace std;
const int maxx=5e5+5;
int c,n,m,d,q;
int f[maxx];
vector<int> v[maxx];
vector<int> g[maxx];
int a[maxx],b[505][500005];
long long ans;
int x,y;
pair<int,int> dfs(int x,int fa,int tot,int fr){
	if(x==y){
		return {tot,fr};
	}
	for(int to:g[x]){
		if(to==fa){
			continue;
		}
		auto it=lower_bound(v[to].begin(),v[to].end(),fr);
		if(*it==fr){
			dfs(to,x,tot,fr);
		}
		else{
			for(int fr2:v[x]){
				dfs(to,x,tot+b[fr][x]+b[fr2][x],fr2);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	int ls=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int to,x;
			scanf("%d%d",&to,&x);
			v[to].push_back(i);
			g[ls].push_back(to);
			g[to].push_back(ls);
			b[i][to]=x;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=INT_MAX;
		for(int fr:v[x]){
			pair<int,int> k=dfs(x,0,0,fr);
			ans=min(ans,1ll*k.first+b[k.second][x]);
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
