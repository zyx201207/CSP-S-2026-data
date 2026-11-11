#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int d[100][100]={};
	int dp[1000][1000]={};
	int n,m;
	int a[100]={};
	int sum=0;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=a[i]-a[j];
		}	
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(d[i][j]>0){
				sum+=d[i][j];
			}
		}
		if(m==sum||((i>=2&&(m-sum)/i)==0)){
			ans=i;
		} 
		sum=0;
	}
	
	cout<<ans;
	return 0;
}