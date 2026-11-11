#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],lst[M],ans[M],dp[N];
bool ed[N];
vector<int>mp[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card6.in","r",stdin);
//	freopen("card6.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!lst[a[i]]){
			ed[i]=1;
			if(i-n) mp[i+1].push_back(i);
		}else
			mp[lst[a[i]]].push_back(i);
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int x:mp[i])
			dp[i]+=dp[x];
		if(ed[i]) ans[a[i]]=dp[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
