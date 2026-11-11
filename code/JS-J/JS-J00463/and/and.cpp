#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans=0;
void dfs(int id,int k,int f,int s){
	if(k==m){
		ans=max(ans,s);
		return;
	}
	if(id>n) return;
	if(f==0) dfs(id+1,k+1,1,a[id]);
	else dfs(id+1,k+1,1,s&a[id]);
	dfs(id+1,k,f,s);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
