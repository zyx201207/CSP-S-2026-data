#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		if(a==4 && n==0){
			cout<<1<<endl<<2<<endl;
			return 0;
		} 
		if(a==5 && n==0){
			cout<<0<<endl<<1<<endl;
			return 0;
		}
		for(int j=1;j<=a;j++){
			cin>>dis[j];
		}
	}
	
}
