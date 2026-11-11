#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10;
int a[N];
int n,m;
ll ans=0;
int pow(int x,int y){
	int res=0;
	while (y){
		if (y&1) res*=x;
		x*=x,y>>=1;
	}
	return res;
}
inline void dfs(int x,int y,ll ad){
	if (y>=m){
		ans=max(ans,ad);
		return;
	}
	for (int i=x+1;i<=n-m+y+1;i++) dfs(i,y+1,ad&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int k=pow(2,31)-1;
	dfs(0,0,k);
	printf("%lld",ans);
}
