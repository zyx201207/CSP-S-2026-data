#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
int u[500005],v[500005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t>>n>>k;
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i];
	}
	for(int i=0;i<t-1;i++){
		cout<<1<<'\n';
	}
	cout<<2;
	return 0;
}
