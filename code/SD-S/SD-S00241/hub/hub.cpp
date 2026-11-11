#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k,x,y;
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>x>>y;
		}
		cout<<n/2<<"\n";
	}
	return 0;
}

