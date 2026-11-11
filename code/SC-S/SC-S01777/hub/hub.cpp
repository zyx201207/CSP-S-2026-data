#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		cout<<abs(n-k)<<"\n";
	}
	return 0;
}