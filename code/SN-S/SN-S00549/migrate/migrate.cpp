#include<bits/stdc++.h> 
using namespace std;
int c,t,n,m;
int a[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--){
		cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n%m>=2)cout<<0<<endl;
			else{
				cout<<(n%m)+1<<endl;
			}
		}
	
	return 0;
}
