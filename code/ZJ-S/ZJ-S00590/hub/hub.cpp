#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		n-=k*2;
		for(int i=1;i<=3;i++){
			n=ceil(1.0*n/2);
		}
		n++;
		cout<<n;
	}
	return 0;
}
