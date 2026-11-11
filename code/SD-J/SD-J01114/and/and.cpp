#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,ans=-0x3f3f3f3f;
long long a[N];
void dfs(int id,long long sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(n-id+1<m-cnt || id>n){
		return;
	}
		if(sum==0){
			dfs(id+1,a[id],cnt+1);
		}
		else{
			dfs(id+1,a[id]&sum,cnt+1);
		}
		dfs(id+1,sum,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
} 
