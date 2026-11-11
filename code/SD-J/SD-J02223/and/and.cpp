#include<bits/stdc++.h>
using namespace std;
int n,m,s,maxx=-1,a[200010],b[200010];
bool vis[200010];
void dfs(int x,int m){
	if(x==m){
		int s=b[1];
		for(int i=1;i<=x;i++) s&=b[i];
		maxx=max(maxx,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[++x]=a[i];
			vis[i]=1;
			dfs(x,m);
			vis[i]=0;
			x--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,m);
	cout<<maxx;
	return 0;
}
