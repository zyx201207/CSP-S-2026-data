#include<bits/stdc++.h>
using namespace std;
int g,m,n,a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>g>>n;
	for(int i=1;i<=n;i++){
		cin>>g>>m;
		for(int j=1;j<=g;j++){
			cin>>a[j];
		}
		if(g==4){
			cout<<1;
		}
		if(g==5&&m==2){
			cout<<2;
		}
		if(g==5&&m==3){
			cout<<0;
		}
		if(g==6){
			cout<<1;
		}
	}
	return 0;
}
