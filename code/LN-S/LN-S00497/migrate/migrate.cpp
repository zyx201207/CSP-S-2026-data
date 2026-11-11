#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll d,n;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d>2){cout<<0<<endl;continue;}
		cout<<(n-1)/d<<endl;
	}
}
