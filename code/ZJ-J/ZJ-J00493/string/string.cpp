#include<bits/stdc++.h>
using namespace std;
long long t,ans,w,h;
const int N=2e6+3;
long long dp[N];
string a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i]>>a[i];
	}
	w=1;
	h=n;
	while(w<h){
		if(a[w]!=a[h]){
			ans+=min(dp[w],dp[h]);
		}
		if(dp[w]>dp[h]){
			dp[w]-=dp[h];
				h-=1;
				
		}else{
			if(dp[w]<dp[h]){
			dp[h]-=dp[w];
			w+=1;
			
			}
		}
			if(dp[w]==dp[h]){
				dp[h]=0;
				dp[w]=0;
				w++;
				h--;
			 
			}
		
	}
	cout<<ans;
	return 0;
}

