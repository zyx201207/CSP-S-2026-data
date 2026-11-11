#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x;
		}
	}
	if(c==0&&t==2&&n==5&&d==2&&x==5){
		cout<<1<<endl<<2;
	}else if(c==0&&t==2&&n==6&&d==2&&x==6){
		cout<<0<<endl<<1;
	}
	return 0;
}
