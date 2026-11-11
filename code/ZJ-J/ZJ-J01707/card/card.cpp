#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans[N],a[N],p[N],pp[N],maxx,dp[5010][3010],f[N],fl,wt[N],cnt[N],dp2[200010][5];
vector<int>g[N];
void dfs(int uu){
	ans[uu]+=cnt[uu];
	for(int vv:g[uu]){
		ans[vv]+=cnt[uu];
//		cout<<vv<<" "<<ans[vv]<<" "<<ans[uu]<<"\n";
		dfs(vv);
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fl=1;
//	fl2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
		if(a[i]<a[i-1])fl=0;
	}
	if(n<=5000&&m<=3000){
		for(int i=n;i>=1;i--){
			if(f[a[i]]==0){
				dp[i][a[i]]++;
				for(int j=1;j<=m;j++){
					dp[i][j]+=dp[i+1][j];
					ans[j]+=dp[i][j];
				}
			}else{
				for(int j=1;j<=m;j++){
					dp[i][j]+=dp[f[a[i]]][j];
					ans[j]+=dp[i][j];
				}
			}
			f[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" "; 
		}
		return 0;
	}
	if(fl){
		for(int i=1;i<=m;i++){
			cout<<p[i]<<" ";
		}
		return 0;
	}
	if(n<=200000&&m<=2){
		for(int i=n;i>=1;i--){
			if(f[a[i]]==0){
				dp2[i][a[i]]++;
				for(int j=1;j<=m;j++){
					dp2[i][j]+=dp2[i+1][j];
					ans[j]+=dp2[i][j];
				}
			}else{
				for(int j=1;j<=m;j++){
					dp2[i][j]+=dp2[f[a[i]]][j];
					ans[j]+=dp2[i][j];
				}
			}
			f[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" "; 
		}
		return 0;
		
	}
	if(n<=200000&&m<=3000){
		for(int i=n;i>=1;i--){
			if(f[a[i]]==0){
				for(int j=1;j<=m;j++){
					dp[a[i]][j]=dp[a[i+1]][j];
					ans[j]+=dp[a[i]][j];
				}
				dp[a[i]][a[i]]++;
				ans[a[i]]++;
			}else{
				for(int j=1;j<=m;j++){
					ans[j]+=dp[a[i]][j];
				}
			}
			f[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" "; 
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(f[a[i]]==0){
			ans[a[i]]=1;
			g[a[i]].push_back(a[i+1]);
			wt[a[i+1]]++;
//			dp[a[i]][a[i]]++;
//			for(int j=1;j<=m;j++){
//				dp[a[i]][j]+=dp[a[i+1]][j];
//				ans[j]+=dp[a[i]][j];
//			}
		}else{
			cnt[a[i]]++;
		}
		f[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(wt[i]==0){
//			ans[i]=cnt[i];
			dfs(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1
*/
