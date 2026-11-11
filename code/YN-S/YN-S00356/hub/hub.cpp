#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int c,t,n,k;
vector<int>g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	long long x=c;
	while(t--){
		cout<<x%2+1<<"\n";
		x=(x*x+x)%(long long)1e4;
	}
	return 0;
}
