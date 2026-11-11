//crystalÄÜÁ¿Ë®¾§
using namespace std;
#include<bits/stdc++.h>
int n;
long long m;
long long a[500005];
long long cost[500005];
long long mx[500005];
bool special=false;
//long long dp[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1); 
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	int max=a[n];
	for(int i=1;i<=n;i++){
		cost[i]=max-a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			mx[n]=1;
		}
		else{
			int dp[n-i+12];
			dp[1]=0;
			for(int j=2;j<=n-i+1;j++){
				dp[j]=dp[j-1]+(j-1)*(cost[j-1]-cost[j]);
			}
			int ret=0;
			for(int k=1;k<=n-i+1;k++){
				if(dp[k]<=m){
					ret=k;
				}
				else{
					break;
				}
			}
			mx[i]=ret;
		}
	}
	//for(int i=1;i<=n;i++){
		//cout<<mx[i];
	//}
	sort(mx,mx+n+1);
	cout<<mx[n];
	return 0;
}
