#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxx=1<<20;
int n,m;
long long a[maxn],b[maxn],ans=-1,ba=-1;
bool vis[maxx]= {};
void dfs(int x) {
	if(x==m+1) {
		ans=b[1];
		//cout<<ans<<endl;
		for(int i=2; i<=m; i++) {
			//cout<<b[i]<<endl;
			ans&=b[i];
		}
		ba=max(ba,ans);
		//cout<<endl;
		return ;
	} else {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
			vis[i]=1;
				b[x]=a[i];
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ba;
	return 0;
}
