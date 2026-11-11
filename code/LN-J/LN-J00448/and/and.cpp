#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long n,m,a[N],dp[N],ans;
void dfs(long long x,long long now,long long cur){
	if(cur == 0) return ;
	if((now + n-x+1) < m)	return ;
	if(now == m){
		ans = max(ans,cur);
		return ;
	}
	dfs(x+1,now,cur);
	if(cur == -1){
		dfs(x+1,now+1,a[x]);
	}
	else{
		dfs(x+1,now+1,cur & a[x]);
	}
	return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<a[i]<<"\n";
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}

