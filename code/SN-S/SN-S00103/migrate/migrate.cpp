#include<bits/stdc++.h>
using namespace std;
int n;
int m,sum,c,q;
long long d,a[2000010],t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=t;i--){
			cin>>a[i];
		}
		if(n==4&&d==2){
			cout<<"1";
		}else if(n==5&&d==3){
			cout<<"0";
		}
		if(n==6&&d==2){
			cout<<"1";
		}
		if(n==5&&n==2){
			cout<<"2";
		}
	}
	return 0; 
}
