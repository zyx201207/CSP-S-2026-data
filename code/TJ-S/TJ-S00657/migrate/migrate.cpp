#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long x[2000010];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<=n;j+d){
			if(n-j==0){
				cout<<'1';
			}
			if(n-j>1){
				cout<<'0';
			}
			if(n-j==1){
				cout<<n/d;
			}
		}
	}
	
	return 0;
}
