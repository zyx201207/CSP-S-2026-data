#include<bits/stdc++.h>
using namespace std ;
long long b[200005],ans=0,jz[200005];
long long dp[25][25];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long cd=0;
	for(int i=1;i<=n;i++)cin>>b[i];
	if(n<=20){
		sort(b+1,b+1+n);
		cout<<b[n-m+1];
		return 0;
	}
	if(m==1){
		sort(b+1,b+1+n);
		cout<<b[n];
		return 0;
	}
	if(m==n){
		ans=b[1]&b[2];
		for(int i=3;i<=n;i++){
			ans&=b[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				ans=max(ans,b[i]&b[j]); 
			}
		}
		cout<<ans;
	}
	return 0;
} 
//5 3
//31 3 1 7 15




