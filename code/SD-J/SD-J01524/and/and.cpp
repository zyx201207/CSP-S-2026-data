#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+5;
int a[N],n,m,maxn=0;
int dfs(int x,int shu,int zhi){
	if(shu==m||x==n) return zhi;
	return max(dfs(x+1,shu+1,zhi&a[x]),dfs(x+1,shu,zhi));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	if(m==1) cout<<maxn;
	else cout<<dfs(1,0,1);
	return 0;
}
