#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<0<<"\n";
		}else{
			if(x[2]-x[1]<2*d){
				cout<<0<<"\n";
			}else if(x[2]-x[1]>3*d){
				cout<<0<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}
	}
} 
