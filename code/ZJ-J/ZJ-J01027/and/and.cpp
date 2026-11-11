#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
ll a[N];
int dp[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<3){
		int mx=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=a[i];
			for(int j=i+1;j<=n;j++){
				sum&=a[j];
				mx=max(mx,sum);
				sum=a[i];
			}		
		}
		cout<<mx;
	}
	else if(m>=3){
		for(int i=1;i<=n;i++){
			dp[1]=a[i];
			for(int k=2;k<=m;k++){
				for(int j=i+1;j<=n;j++){
					if(vis[j]==1){
						continue;
					}
					if(dp[k-1]&a[j]>dp[k]){
						vis[j]=1;
						dp[k]=dp[k-1]&a[j];
					}
				}
			}
		}
		cout<<dp[m];
	}
	return 0;
}

