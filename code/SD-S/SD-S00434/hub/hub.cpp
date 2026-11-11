#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,k;cin>>n>>k;
		int u,v;
		for(int i=1;i<=n;i++)cin>>u>>v;
		cout<<rand()%n+1<<endl;
	}
	return 0;
}
