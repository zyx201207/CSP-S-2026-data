#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, t;
int n, d, x[N];
queue<pair<int,int>> q;
vector<int> edge[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(edge, 0, sizeof(edge));
		for(int i = 1; i <= n; i++) cin>>x[i];
		for(int i = 1; i <= n; i++){
			int j = i;
			while(x[j+1]-x[i]<=d){
				j++;
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
		int yu[N],mi[N],ans=0;
		
		
		for(int i = 1; i <= n; i++){
			memset(mi, -1, sizeof(mi));
			memset(yu, 0, sizeof(yu));
			q.push({i,0});
			while(q.size()){
				int u=q.front().first,kl=q.front().second;
				q.pop();
				if(mi[u]==-1){
					mi[u]=kl;
					yu[u]++;
				}
				if(mi[u]==kl){
					yu[u]++;
				}
				for(auto v : edge[u]){
					q.push({v,kl+1});
				} 
			}
			
			for(int j = i; j <= n; j++)
				if(yu[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}