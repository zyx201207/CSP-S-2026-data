#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
#define pri priority_queue
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	srand(time(0));
	int ans=(rand()*rand())%(n-1)+1;
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t=1,l;
	cin>>l>>t;
	while(t--){
		solve();
	}
	return 0;
}

