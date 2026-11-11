//#include<bits/stdc++.h>
//using namespace std;
//int dp[200005],a[200005];
//vector<int> maxh_bit[32]
//int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		int 
//		for(int j=31;j>=0;j--){
//			if(a[i]&(1<<j)){
//				dp[j]=max(dp[j],a[i]);
//				maxh_bit[j].push_back(a[i]);
//				break;
//			}
//		}
//	}
//	sort(a+1,a+1+n)
//	dp[1]=a[n];
//	for(int i=1;i<=m;i++){
//		for(int j=31;j>=0;j--){
//			
//		}
//	}
//	cout<<dp[m];
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,ans;
bool vis[200005];
void dfs(int c,int b){
	if(c==m){
		ans=max(ans,b);
		return ;
	}
	int i=1;
	while(i<=n){
		if(vis[i]==0){
			vis[i]=1;
			dfs(c+1,(b^a[i]));
			vis[i]=0;
		}cout<<c;
		i++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}//5 3 31 3 1 15 7
