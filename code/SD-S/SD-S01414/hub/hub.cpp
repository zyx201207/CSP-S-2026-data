#include<bits/stdc++.h>
#define int long long
using namespace std;
//×¢Òâ¶à²âÇå¿Õ
int n,k;
vector<int>v[1000010]; 
int chose[1000010],vis[1000010],dis[1000010];
void bfs(int st){
	vis[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i:v[t]){
			if(!vis[i]&&chose[i]){
				vis[i]=1;
				q.push(i);
			}
		}
	}
} 
void BFS(){
	for(int i=1;i<=n;i++)dis[i]=-1;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(chose[i])q.push(i),dis[i]=0;
	}
	while(!q.empty()){
		int t=q.front();q.pop();
		for(auto i:v[t]){
			if(dis[i]==-1){
				dis[i]=dis[t]+1;
				q.push(i);
			}
		}
	}
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)v[i].clear(),chose[i]=0,vis[i]=0;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans=1e18;
	int mask=(1<<n);
	for(int i=0;i<mask;i++){
		int sum=0,cnt=0;
		for(int j=1;j<=n;j++)chose[j]=0,vis[j]=0;
		for(int j=0;j<n;j++){
			if(((i>>j)&1)==1)sum++,chose[j+1]=1;
		}
		if(sum!=k)continue;
		for(int j=1;j<=n;j++){
			if(chose[j]&&!vis[j]){
				bfs(j);
				cnt++;
			}
		}
		if(cnt>2)continue;
		BFS(); 
		int mx=0;
		for(int j=1;j<=n;j++)mx=max(mx,dis[j]);
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--)work();
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/ 
