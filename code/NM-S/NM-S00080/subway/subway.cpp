#include<bits/stdc++.h>
using namespace std;

struct Dot{
	int id;
	int tie;
};

int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m];
	int sum[m];
	int a[n][m];
	int k[n][m];
	int tim[n][n];
	vector<int> to[m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			tim[i][j] = INT_MAX;
		}
	}
	for(int i = 0;i < m;i++){
		cin>>w[i];
	}
	for(int i = 0;i < n;i++){
		cin>>sum[i];
		for(int j = 0;j < sum[i];j++){
			cin>>a[i][j]>>k[i][j];
			to[a[i][j]].push_back(i);
		}
	}
	for(int Q = 0;Q < q;Q++){
		int s,t;
		cin>>s>>t;
		if(tim[s][t] != INT_MAX){
			cout<<tim[s][t]<<endl;
			continue;
		}
		bool used[m];
		memset(used,false,sizeof(used));
		queue<Dot> q;
		q.push({s,0});
		while(!q.empty()){
			Dot x;
			x = q.front();
			q.pop();
			used[x.id] = true;
			for(int i = 0;i < (int)to[x.id].size();i++){
				int bit;
				for(int j = 0;j < m;j++){
					if(a[to[x.id][i]][j] == x.id){
						bit = i;
						break;
					}
				}
				for(int j = 0;j < sum[to[x.id][i]];j++){
					if(used[a[to[x.id][i]][j]]) continue;
					q.push({a[to[x.id][i]][j],x.tie+k[to[x.id][i]][j]+k[to[x.id][j]][bit]});
					tim[s][a[to[x.id][i]][j]] = min(tim[s][a[to[x.id][i]][j]],x.tie+k[to[x.id][i]][j]+k[to[x.id][j]][bit]);
				}
			}
		}
		cout<<tim[s][t]<<endl;
	}
	return 0;
}
