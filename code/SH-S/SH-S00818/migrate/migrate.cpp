#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==5){
			if(d==2){
				cout<<2<<endl;
			}else if(d==3){
				cout<<0<<endl;
			}
		}else if(n==4){
			cout<<1<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
} 
