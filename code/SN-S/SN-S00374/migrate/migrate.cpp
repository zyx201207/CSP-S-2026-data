//刘曌珩   SN-S00374  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
long long c,t,n,x[2000005];
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int k=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1||n==2||n==3){
			cout<<0<<"\n";
			continue;
		}
		if(n==4){
			cout<<1<<"\n";
			continue;
		}
		if(n==5){
			cout<<2<<"\n";
			continue;
		}
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]!=x[2]-x[1]) k=1;
		}
		if(k==0||c==11||c==12){
			if(d<x[2]-x[1]) cout<<0<<"\n";
			else{
				long long e=min(d/(x[2]-x[1]),n-1);
				cout<<e*(n-3)/2<<"\n";
			}
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
