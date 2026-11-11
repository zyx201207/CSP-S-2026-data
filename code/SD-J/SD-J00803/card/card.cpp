#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int a[N],dp[N],lst[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],dp[i]=1;
	for(int i=n;i>=1;i--)
		if(!lst[a[i]]) lst[a[i]]=i;
	for(int i=1;i<=n;i++){
		ans[a[i]]+=dp[i];
		dp[lst[a[i]]+1]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<' ';
	}
	return 0;
}
