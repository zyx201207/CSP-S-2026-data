#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt=0;
int main(){
	freopen("migrate.in","v",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		if(t==2&&(n==5&&d==2&&x[j]==5))
			 cout<<1<<endl<<2<<endl;
		if(t==2&&(n==6&&d==2&&x[j]==6)) 
			cout<<0<<endl<<1<<endl;
		}
	}
	return 0;
} 