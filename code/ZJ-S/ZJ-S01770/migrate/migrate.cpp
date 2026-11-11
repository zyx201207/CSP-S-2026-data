#include<bits/stdc++.h>
using namespace std;
long long a[2000020];
long long sef[2000020];
long long pre[2000020];
int dp[5050][5050];
void solve(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d){
				dp[i][j]=-0x3f3f3f3f;
			}else{
				int k=1;
				while(a[j]-a[j-k]<=d&&(j-k)>i){
					if(k>2){
						break;
					}
					k++;
				}
				dp[i][j]=dp[i][j-1]+k-2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int c;
	cin>>c;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}