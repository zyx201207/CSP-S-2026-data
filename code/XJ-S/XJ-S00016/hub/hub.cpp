#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[1000010],v[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	int flag=0;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		int ans=0;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
			ans=min(v[i],v[j-1]);
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
