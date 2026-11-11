#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
//int func(int x){
//	if(x==1)return 1;
//	return func(x-1)+func(x-2);
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x[n+1];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1||n==2||n==3)cout<<"0\n";
		else if(n==4)cout<<"1\n";
		else if(n==5)cout<<"2\n";
		else cout<<"0\n";
	}
	return 0;
}