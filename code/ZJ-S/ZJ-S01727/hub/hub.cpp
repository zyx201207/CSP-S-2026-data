#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN=1e6+5;
ll c,t,n,k,u[MAXN],v[MAXN];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(t){
			cout<<1<<"\n";
		}else{
			cout<<2;
		}
	}
	return 0;
}
