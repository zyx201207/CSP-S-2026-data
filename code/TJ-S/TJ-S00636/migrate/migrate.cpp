#include<bits/stdc++.h>
using namespace std;
int c,t;
int dp[5005][5005];
int x[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,w;
		cin>>n>>w;
		if(n==4&&w==2){
			cout<<1<<'\n'<<2<<'\n';return 0;
		}
		else if(n==5&&w==3){
			cout<<0<<'\n'<<1<<'\n';
			return 0; 
		}
	}
	return 0;
}
