#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m;
int a[N],ans = 0;
inline void dfs(int x,int step,int res){
	if(step == m){
		ans = max(ans,res);
		return;
	}
	for(int i=x+1;i<=n-(m-step-1);i++){
		dfs(i,step+1,res & a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m;i++){
		dfs(0,0,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
