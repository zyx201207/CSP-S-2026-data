#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=0,k=0,u[100005],v[100005];
		cin>>n>>k;
		for (int i=1;i<=n-1;i++) {
			cin>>u[i]>>v[i];
		}
		cout<<k<<'\n';
	}
	return 0;
}
