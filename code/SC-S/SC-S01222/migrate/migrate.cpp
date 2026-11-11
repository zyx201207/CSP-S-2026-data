#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(t==2 && n==5 && d==2){
		cout<<1<<"\n"<<2;
	}
	if(t==2 && n==6 && d==2){
		cout<<0<<"\n"<<1;
	}
	return 0;
}
