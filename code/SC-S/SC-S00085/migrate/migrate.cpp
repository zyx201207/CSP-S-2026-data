#include<bits/stdc++.h>
using namespace std;
const int N(2e6 + 10);
int c,t;
int n,d;
int dist[N];
int cnt,cnt2;
int way = 0;
queue<pair<int,int> > q;
bool bfs(int u,int v){
	cnt2 == 0;
	while(!q.empty()){
		int zz = q.front().first,va = q.front().second;
		q.pop();
		if(zz == dist[v] && va <= way && way != 0){
			cnt2++;
			continue;
		}
		else if(way == 0 && zz == dist[v]){
			way = va;
			cnt2++;
			continue;
		}
		for(int i = 1;i <= d;i++){
			if(zz + i <= dist[v]){
				q.push({zz + i,va + 1});
			}
		}	
	}
	if(cnt2 == 2){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>dist[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				q.push({dist[i],0});
				if(bfs(i,j)){
					cnt++;
				}
				way = 0;
			}
		}
		cout<<cnt<<endl;
		cnt = 0;
		memset(dist,0,sizeof(dist));
	}
	return 0;
}