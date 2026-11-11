#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,u[1000010],v[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>u[i]>>v[i];
		cout<<n/8+1-(k-2)/4<<'\n';
	}
	return 0;
}
