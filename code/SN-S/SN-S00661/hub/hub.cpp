#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		ll cnt=n*t%k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
		cout<<cnt<<endl;
		cnt+=t;
	}
	return 0;
}
