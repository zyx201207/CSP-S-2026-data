#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
long long a[N],dp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		
		for(int i=1;i<=n;i++){
				if(a[i]==a[n]){
					dp[a[i]]++;
				}else{
					dp[1]++;
					dp[2]++;
				}
			
		}
		if(m==1)cout<<dp[1];
		else cout<<dp[1]<<" "<<dp[2];
	}
	return 0;
}
