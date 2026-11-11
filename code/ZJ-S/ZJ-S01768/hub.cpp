#include <bits/stdc++.h>
using namespace std;
const int M = 2e6+ 5;
vector<int> e[M];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
   	int c,t;
   	cin >> c >> t;
   	while(t--){

   		int n,k;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int d[M],ans = 2e6+5;
		for(int i = 1;i <= n;i++)d[i] = 0;

		for(int i = 1;i <= n;i++){
			int maxx = 0;

		
			for(auto to:e[i]){
				if(d[to] > d[i] + 1)d[to]= d[i] + 1;
				
				maxx = max(maxx,d[to]);
			}
			ans = min(ans,maxx);
			
			
		}
		cout << ans << '\n';
	}
}