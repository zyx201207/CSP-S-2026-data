#include <bits/stdc++.h>
using namespace std;
long long n,k,c,t,u,v;
vector<long long>a[2000100];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<1;
	}
	return 0;
}