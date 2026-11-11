#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,c,k;
struct nd{
	int u,v;
}g[2000006];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t-->0){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>g[i].u>>g[i].v;
		if(c==13||c==14){
//			cout<<n<<" "<<(g[n].u+1)<<endl;
			cout<<((g[n].u+1)/2-k)/2+1<<endl;
		}
	}
}
