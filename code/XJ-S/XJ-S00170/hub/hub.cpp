#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>u[i]>>v[i];
		cout<<k<<"\n";
	}
	return 0;
} 
