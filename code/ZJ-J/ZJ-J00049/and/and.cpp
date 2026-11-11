#include<bits/stdc++.h>
using namespace std;
#define FILENAME "and"
long long n,m,a[200001],ans; 

void dfs(int i, int cnt, int res){
	if(cnt!=0 && res<ans) return;
	if(cnt==m){
		ans=res;
		return;
	}
	if(i>n) return;
	dfs(i+1,cnt,res);
	dfs(i+1,cnt+1,(cnt)?(res&a[i]):a[i]);

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=-1;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}