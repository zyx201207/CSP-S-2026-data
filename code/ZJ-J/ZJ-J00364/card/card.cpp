#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],nxt[N],now[N],f[N],ans[N];
int g[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(now[a[i]]==0)now[a[i]]=i;
		nxt[i]=now[a[i]];
	}
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=1;i<=n;i++){
		int x=nxt[i];
		if(nxt[i]==i){
			ans[a[i]]+=f[i];
			f[i+1]+=f[i];
		}
		else f[nxt[i]]+=f[i];
	}
//	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
//	printf("\n");
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
//	printf("\n");
	return 0;
}
