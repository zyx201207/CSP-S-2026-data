#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q1;
long long w[500001];
vector<long long>e[500501],b[500501]; 
long long vis[500501],dis[500501];
queue<long long>q;
long long tmp,tmp2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>tmp>>tmp2;
			e[i].push_back(tmp+500);
			b[i].push_back(tmp2);
			e[tmp+500].push_back(i);
			b[tmp+500].push_back(tmp2);
		}
	}
	while(q1--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		vis[x+500]=1;
		memset(dis,0x3f,sizeof(dis));
		dis[x+500]=0;
		if(c>=12&&c<=19){
			for(q.push(x+500);!q.empty();q.pop()){
				int t=q.front();
				for(int i=0;i<(int)e[t].size();i++){					
					if(!vis[e[t][i]]){
						dis[e[t][i]]=dis[t]+b[t][i];
						vis[e[t][i]]=1;
						q.push(e[t][i]);
					}
				}
			}
		}else
		for(q.push(x+500);!q.empty();q.pop()){
			int t=q.front();
			vis[t]=0;
			for(int i=0;i<(int)e[t].size();i++){
				if(dis[e[t][i]]>dis[t]+b[t][i]){
					dis[e[t][i]]=dis[t]+b[t][i];
					if(!vis[e[t][i]]){
						vis[e[t][i]]=1;
						q.push(e[t][i]);
					}
				}
			}
		}
		cout<<dis[y+500]+w[x]+w[y]<<'\n';
	}
}/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3*/
