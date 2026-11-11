#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int> >a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		a.clear();
		a.resize(n+10);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
	}
	return 0;
}
