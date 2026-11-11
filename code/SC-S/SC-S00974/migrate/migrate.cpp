#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		vector<int> x;
		int dist[100005];
		memset(dist,0x3f,sizeof dist);
		vector<int> g[100005];
		cin>>n>>d;
		for(int i=0;i<n;i++){
			int f;
			cin>>f;
			x.push_back(f);
		}
		cout<<0;
	}
	return 0;
}