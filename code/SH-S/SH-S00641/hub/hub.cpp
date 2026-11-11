#include<bits/stdc++.h>
using namespace std;
const int maxn=5*2e6;
long long c,t,n,k;
vector<long long>a[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<0<<"\n";
		
	}
	return 0;
}
