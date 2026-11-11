#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;

int n,m;
int a[N],las[N],nxt[N],sz[N];
ll ans[N];
vector<int>g[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		nxt[i]=(las[a[i]]==i)?i+1:las[a[i]]+1;
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]<=n){
			g[nxt[i]].push_back(i);
		}
	}
	for(int j=1;j<=n;j++){
		sz[j]=1;
		for(int u:g[j]){
			sz[j]+=sz[u];
		}
	}
	for(int j=1;j<=n;j++){
		ans[a[j]]+=sz[j];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
