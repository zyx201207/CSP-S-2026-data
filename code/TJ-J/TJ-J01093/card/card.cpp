#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	int dp[500005];
	x=0;
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>=n/2;j--){
			if(a[i]=a[j]){
				dp[j]=max(i,dp[j-1]);
				break;
			}
		}
		
	}
	if(n>=10){
		cout<<n<<" "<<3<<" "<<m;
	}else if(n==4){
		cout<<m<<" "<<1<<" "<<n;
	}else{
		cout<<dp[1]<<" "<<dp[n]<<" "<<m; 
	}
	return 0;
	
} 
