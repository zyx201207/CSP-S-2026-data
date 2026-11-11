#include<bits/stdc++.h>
using namespace std;
long long C,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int n,d,XX[571935];
		cin>>n>>d;
		if(n<4){
			cout<<0;
		}else{
			for(int i=1;i<=n;i++){
				cin>>XX[i];
			} 
			int TT=XX[2]-XX[1];
			if(d<=2*TT) cout<<0;
			else{
				int WW=d/TT+1;
				cout<<n-WW;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
