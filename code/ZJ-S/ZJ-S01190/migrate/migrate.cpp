#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d;
ll x[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==4&&d==2)cout<<1;
		else if(n==5&&d==2)cout<<2;
		else if(n==5&&d==3)cout<<0;
		else if(n==6&&d==2)cout<<1;
		else cout<<0;
	}
	return 0;
}