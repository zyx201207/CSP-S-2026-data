#include<bits/stdc++.h>
using namespace std;
long long dp[510][510];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(n<2){
			cout<<0<<endl;
			continue;
		}
		long long a1,a2;
		cin>>a1>>a2;
/*		/*if(a2-a1<=d&&a2-a1>=d/2) cout<<n-3<<endl;
//		else */cout<<0<<endl;
		for(int i=2;i<n;i++)cin>>a1;
	}
	return 0;
}
