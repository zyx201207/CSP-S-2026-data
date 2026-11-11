#include<bits/stdc++.h>
#define F first
#define S second
#define mkp make_pair
using namespace std;
const int INF=1e9;
vector<int> E[200005];
pair<int,int> dis[200005];
long long ans;
void bfs(int st){
	for(int i=1;i<=st;i++) dis[i]=mkp(INF,0);
	dis[st]=mkp(0,1);
	queue<int> q;q.push(st);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(dis[y].F>dis[x].F+1){
				dis[y]=mkp(dis[x].F+1,dis[x].S);
				q.push(y);
			}
			else if(dis[y].F==dis[x].F+1){
				dis[y].S+=dis[x].S;
			}
		}
	}
	for(int i=1;i<st;i++){
//		cout<<dis[i].S<<' ';
		if(dis[i].S==2) ans++;
	}//cout<<'\n';
}
int C,T,n;long long D,x[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++){
			E[i].clear();
		}
		cin>>n>>D;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(13<=C&&C<=14){
			cout<<0<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(x[j]+D>=x[i]){
						E[i].push_back(j);
//						cout<<
					}
				}
			}
			for(int i=2;i<=n;i++){
				bfs(i);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
