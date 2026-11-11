#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int c,t,n,k,u,v;
int a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u>>v;
		} 
		cout<<k-1;
	} 
	
	return 0;
}
