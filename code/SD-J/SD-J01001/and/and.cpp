#include<bits/stdc++.h>
using namespace std;
int va[200005];//cost=1
int dp[200005];
bool check[200005];
int anss=-1;
int m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;//非负整数个数，选取个数 
    for(int i=1;i<=n;i++) cin>>va[i];
    for(int i=0;i<=m;i++) dp[i]=2147483647;
    for(int i=1;i<=n;i++){
    	for(int j=m;j>=1;j--){
    		if(check[j]==0){
    			dp[j]=max(-1,dp[j-1]&va[i]);
    			check[j]=1;
			}
    		else dp[j]=max(dp[j],dp[j-1]&va[i]);
		}
	}
	cout<<dp[m];
	return 0;
} 
