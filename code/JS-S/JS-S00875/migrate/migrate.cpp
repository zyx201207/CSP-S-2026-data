#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

const int N=2000005;

int c,t,n,m,L[N],R[N],a[N],f1[N],f2[N],f3[N];
ll d,ans,x[N];

inline int z(int x){
	return R[x]-R[x-1];
}

void solve(int u){
	int i,j,l,r,v=R[u],w=R[R[u]];

	if(u==v){
		f1[u]=f2[u]=f3[u]=0;
		return ;
	}

	if(v==w){
		f1[u]=z(u),f2[u]=f3[u]=0;
		return ;
	}

	f1[u]=f1[v],f2[u]=f2[v],f3[u]=f3[v];

	if(v>u+1) ans+=min(R[v-1],w-1)-min(R[v-2],w-1);

	if(L[w]<v){
		f3[u]=f1[u]+1;
		f1[u]=f2[u]=0;

		if(L[w]==v-1) ans+=f3[u];
		if(L[w]<v-1||L[L[w]]<u) f3[u]=0;
		if(v>u+1&&L[v-1]==u) f2[u]+=min(R[v-1],w-1)-min(R[v-2],w-1);
	}else{
		ans+=f2[u]+f3[u];

		if(v>u+1&&L[v-1]==u) f2[u]+=z(v-1);
	}

	f1[u]+=z(u);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int i,j,l,r;

	scanf("%d%d",&c,&t);

	while(t--){
		scanf("%d%lld",&n,&d);

		for(i=1;i<=n;i++)
			scanf("%lld",&x[i]);

		for(r=l=1;r<=n;r++){
			while(x[r]-x[l]>d) l++;

			L[r]=l;
		}

		for(r=l=n;l>=1;l--){
			while(x[r]-x[l]>d) r--;

			R[l]=r;
		}

		ans=0;

		for(i=n;i>=1;i--) solve(i);

		printf("%lld\n",ans);
	}

	return 0;
}