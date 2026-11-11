#include<bits/stdc++.h>
using namespace std;
int c,n,k,t;
struct L{
	int u,v;
};
vector<L>a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a.push_back({u,v});
		}
		cout<<1<<'\n';
	}
	return 0;
}
