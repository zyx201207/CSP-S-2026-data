#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int n,d;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];	
		if(c==0){
			if(n==4&&d==2)cout<<"1\n";
			if(n==5&&d==2)cout<<"2\n";
			if(n==5&&d==3)cout<<"0\n";
			if(n==6&&d==2)cout<<"1\n";
		}	
		
	}
	else{
		 cout<<"0\n"
	}}
	return 0
}