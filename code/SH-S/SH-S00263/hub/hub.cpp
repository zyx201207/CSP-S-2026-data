#include<bits/stdc++.h>
using namespace std;
bool vst[2000009];
int d[2000009];
vector<int> g[2000009];
int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		bool A = 1;
		if(n % 2 == 0) A = 0; 
		for(int i = 0;i < n - 1;i++){
			vst[i + 1] = 0;
			int u,v;
			cin>>u>>v;
			u--;v--;
			if(v != (i + 1)) A = 0;
			if(A){
				if(i < n / 2){
					if(u != i) A = 0;
				}else{
					if(u != (i - n / 2)) A = 0;
				}
			}
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(A){
			cout<<(n / 2 + 2 + 3 - k) / 4<<endl;
			continue;
		}
		int maxd = -1,maxi = 0;
		queue<int> q;
		vst[0] = 1;d[0] = 0;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0;i < g[u].size();i++){
				int v = g[u][i];
				if(vst[v]) continue;
				if(maxd < d[u] + 1){
					maxd = d[u] + 1;
					maxi = v;
				}
				vst[v] = 1;
				q.push(v);
				d[v] = d[u] + 1;
			}
		}
		for(int i = 0;i <= n;i++){
			vst[i] = 0;
			d[i] = 0;
		}
		vst[maxi] = 1;maxd = 0;
		q.push(maxi);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0;i < g[u].size();i++){
				int v = g[u][i];
				if(vst[v]) continue;
				vst[v] = 1;
				q.push(v);
				d[v] = d[u] + 1;
				maxd = max(maxd,d[v]);
			}
		}
		cout<<(maxd + 3) / 4<<endl;
		for(int i = 0;i <= n;i++){
			g[i].clear();
		}
	}
	return 0;
}
