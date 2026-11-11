#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m,a[maxn],ls[maxm],ans[maxm];
int dp[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ls[a[i]]=i;
		dp[i]++;
	}
	for(int i=1;i<=n;i++){
		int idx=ls[a[i]]+1;
		ans[a[i]]+=dp[i];
		dp[idx]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}