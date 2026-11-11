#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int qwer=0;qwer<t;qwer++){
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}if((a[1]-a[0])*3>d and (a[1]-a[0])*2<d){
			cout<<n-3;
		}else{
			cout<<0;
		}
	}
	return 0; 
}
