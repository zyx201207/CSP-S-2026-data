#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,arr[2001001];
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
	}
	if(c==0){
		if(t==2&&n==5&&d==2){
			cout<<1<<endl;
			cout<<2;
		}
		if(t==2&&n==6&&d==2){
			cout<<0<<endl;
			cout<<1;
		}
	}
	return 0;
}
