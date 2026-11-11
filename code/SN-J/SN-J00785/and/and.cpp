#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxx=-1;
bool vis[200005];
void dfs(int d,int sum){
	if(d==m){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(d!=0)dfs(d+1,sum&a[i]);
			else dfs(d+1,a[i]);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0);
	cout<<maxx;
	return 0;
}

