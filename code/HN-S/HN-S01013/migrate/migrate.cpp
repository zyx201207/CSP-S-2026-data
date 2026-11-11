#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000+10;
vector<int>vec[N];
int c,T;
int X[N];
int dis[N];
int vis[N];
int n,d;
void bl(){
	int ans=0;
	for(int i=1;i<=n;i++){
		fill(dis,dis+n+1,-1);
		fill(vis,vis+n+1,0);
	//	fill(vis,vis+n+1,0);
		queue<int>q;
	//	vis[1]=1;
		q.push(i);
		dis[i]=0;
		while(!q.empty()){
			int u=q.front();
	//		cout<<u<<'\n';
			q.pop();
			int v=u+1;
			while(v<=n){
				if(X[v]-X[u]>d){
					break;
				}
				if(dis[v]==-1){//还没有来过 
					dis[v]=dis[u]+1;
					q.push(v);
				}
				else{//已经来过了 
					if(dis[v]==dis[u]+1){ 
						//够成双 
						if(vis[v]==0){//是第二次选 
							ans++;
//							cout<<i<<' '<<v<<'\n';
						}
						else if(vis[v]==1){//以前来过两次了 
							ans--;//把之前的答案消除掉 
						}
						vis[v]++;
					}
				}
				v++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
void slove(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>X[i];
	if(c==11||c==12){
		//特殊A
		if(d<=X[2]-X[1]){
			cout<<0;
			return;
		}
		else{
			 cout<<n-(d/(X[2]-X[1]))-2;
		}
		return;
	}
	if(n<=5000){
		bl();
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		slove();
	}
	return 0;
}

