#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=300010;

int ans[N],lst[N];
bool vis[N]={1};
int n,m,a[N],ll[M];

int dfs(int u){
	int res=1,r;
	if(!vis[lst[u]]){
		vis[lst[u]]=1;
		r=dfs(lst[u]);
	}
	if(!vis[u-1]){
		vis[u-1]=1;
		res+=dfs(u-1);
	}
	ans[a[u]]+=res;
	return res+r;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[i]=ll[a[i]];
		ll[a[i]]=i;
	}
	vis[n]=vis[0]=1;
	dfs(n);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
