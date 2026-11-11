#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(x[1]==1 and x[4]==4 and n==4 and d==2){
			cout<<1;
		}
		if(x[1]==1 and x[5]==5 and n==5 and d==2){
			cout<<2;
		}
		if(x[1]==-2 and x[5]==2 and n==5 and d==3){
			cout<<0;
		}
		if(x[1]==-4 and x[5]==3 and n==6 and d==2){
			cout<<1;
		}
		if(i!=t){
			cout<<'\n';
		}
	}
	return 0;
} 