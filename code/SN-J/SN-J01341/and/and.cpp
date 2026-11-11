#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],vis[2000005];
int n,m;
int maxn=0;
void dfs(int x,int sum,int cnt){
	if(x>n){
		if(cnt==m){
			maxn=max(sum,maxn);
		}
		return ;
	}
	vis[x]=1;
	if(sum==0){
		sum=a[x];
		dfs(x+1,sum,cnt+1);
	}else dfs(x+1,sum&a[x],cnt+1);
	
	vis[x]=0;
	dfs(x+1,sum,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << maxn;
	return 0;
}
