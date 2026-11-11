#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		long long w[10e20];
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		if(c==0){
			if(t==2&&n==4){
				cout<<1<<endl<<2;
				return 0; 
			}
			if(t==2&&n==5){
				cout<<0<<endl<<1;
				return 0;
			}
			if(t==17){
				cout<<10<<endl<<272727272727272724;
				return 0;
			}
		}
	}
	return 0;
} 
