#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,x;
	int a,b;
	cin>>n;
	cin>>d;
	cin>>x;
	cin>>a;
	cin>>b;
	for(int i=1;i<=n;i++){
		x/d==a;
	}
	for(int j=1;j<=n;j++){
		n*a==b;
	}
	cout<<b<<endl<<a;
	
	return 0;
}
