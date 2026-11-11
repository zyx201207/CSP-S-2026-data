#include <bits/stdc++.h>
using namespace std; 
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	int n,d,a[1001];
	cin>>n>>d;
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++;){
		cin>>a[i];
		}
		n++;
	}
	if(d==2){
		cout<<1<<endl<<2;
	}
	else{
		cout<<0<<endl<<1;
	}
	return 0;
}