#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	double pi=3.1415926; 
	while(t--){
		cout<<(int)(pi*pi)%3;
		pi=pi*pi;
	}
	return 0;
}
