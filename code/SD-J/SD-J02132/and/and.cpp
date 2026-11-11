#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+5;
int s[N];
const int INF = -1e18;
int ans = INF;
int dfs(int num,int cnt,int sum){
	if(cnt>m){
		ans=max(ans,sum);
		return ans;
	}
	if(num>n) return INF;
	if(n-num<m-cnt) return INF;
	int a = s[num];
	dfs(num+1,cnt+1,sum&a);
	dfs(num+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,dfs(i,1,s[i]));
	}
	cout<<ans;
	return 0;
}
