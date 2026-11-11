#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
const int M=300010;
void solve(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	vector<int>a(n+2,0);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	vector<int>lst(m+2,0);
	vector<int>ans(m+2,0);
	vector<int>dp(n+2,0);
	for(int i=n;i>=1;i--){
		dp[i]=1;
		if(lst[a[i]]==0){
			lst[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=dp[i];
		dp[lst[a[i]]+1]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		printf("%lld",ans[i]);
		if(i!=m)printf(" ");
	}
	printf("\n");
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
