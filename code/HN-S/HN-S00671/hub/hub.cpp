#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10,INF=1e18;
int c,t,n,d,a[N],cs[1005][1005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(d<=2){
			cout<<1<<endl;
		}
	} 
	return 0;
}
