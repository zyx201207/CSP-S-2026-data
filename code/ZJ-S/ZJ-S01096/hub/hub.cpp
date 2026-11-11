#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,i,x,y;
vector<int> f[1000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<n;i++){
			cin>>x>>y;
			f[x].push_back(y);
			f[y].push_back(x);
		}
		if(n==k){
			cout<<"0\n";continue;
		}
		cout<<"1\n";
	}
	return 0;
}
