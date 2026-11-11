#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
int n,m,k,a[500010],b[500010];
ll sum[500010];
unordered_map<int,unordered_map<int,int> > dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		k=a[i];
		if(b[k]!=0){
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[b[k]][j];
				sum[j]+=dp[i][j];
			}
		}else{
			dp[i][k]++;
			for(int j=1;j<=m;j++){
				dp[i][j]+=dp[i+1][j];
				sum[j]+=dp[i][j];
			}
		}
		b[k]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}