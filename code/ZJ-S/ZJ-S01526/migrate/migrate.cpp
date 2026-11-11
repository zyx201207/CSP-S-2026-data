#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10,M=5010;
ll c,t,n,d,x[N],plan[M][M],cnt[M][M],ans;
int dfs(int a,int b,int stp,int ned){
	if(stp>ned) return x[a]==x[b];
	if(x[a]+(ned-stp+1)*d<x[b]) return 0;
	int res=0;
	for(int i=a+1;i<=b;i++)
		if(x[i]-x[a]<=d) res+=dfs(i,b,stp+1,ned);
		else break;
	return res;
}
bool check(int a,int b){
	int now=x[a],cnt=0;
	while(now<x[b]){
		auto pos=upper_bound(x+1,x+n+1,now+d)-x-1;
		now=x[pos];
		cnt++;
	}
	return dfs(a,b,1,cnt)==2;
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(check(i,j)) ans++;
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}