#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,dp[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>c>>d;
		for(int j=1;j<=c;j++){
			cin>>dp[j];
		}
		if(dp[2]-dp[1]<=d){
			cout<<c-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
} 
