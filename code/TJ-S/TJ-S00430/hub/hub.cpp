#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		int u[2000005],v[2000005];
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		for(int j=1;j<n;j++){
			cin>>u[i]>>v[i];
		}
		cout<<k-1<<"\n";
	}
	return 0;
}

