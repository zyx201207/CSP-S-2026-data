#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
vector<int>v[100010];
int vis[100010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<ceil(1.0*((n-1)/2-k)/4)+1<<'\n';
	}
	return 0;
}
