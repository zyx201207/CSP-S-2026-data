#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,c,T;
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	ll p=a[2]-a[1];
	if(d<p){
		cout<<0<<"\n";
	}
	return 0;
}
