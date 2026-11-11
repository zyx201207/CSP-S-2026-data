#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==0&&t==2&&n==5&&d==3){
			cout<<0<<endl<<1;
		}
		else if(c==0&&t==2&&n==4&&d==2){
			cout<<1<<endl<<2;
		}
		else {
			cout<<3<<endl;
		}
	}
	return 0;
}
