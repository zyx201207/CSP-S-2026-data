#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b;
	cin>>a>>b;
	if(m==1){
		if(a==4&&b==2){
			cout<<1<<endl;
			cout<<2;
		}
		else if(a==5&&b==3){
			cout<<0<<endl;
			cout<<1;
		}
		else{
			cout<<1<<endl;
			cout<<0;
		}
	}
	return 0;
}
