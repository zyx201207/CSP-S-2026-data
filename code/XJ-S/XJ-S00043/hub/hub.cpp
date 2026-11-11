#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5;
int c,n,t,k,u[N],v[N],ans;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
			ans=min(v[i]-u[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
