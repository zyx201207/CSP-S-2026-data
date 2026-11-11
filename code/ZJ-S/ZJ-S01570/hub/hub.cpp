#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		cout<<((n+1)/2-m)/4+1<<endl;
	}
	return 0;
}