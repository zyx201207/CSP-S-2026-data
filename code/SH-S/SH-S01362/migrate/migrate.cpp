#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000010],st,minn,ed,vis[2000010],cnt,c,T;
vector<int> g[2000010];
struct node{
	int val,dis;
};
queue<node> q;
bool flag=0;
void bfs(int x,int step){
	q.push({x,step});
	while(!q.empty()){
		node t=q.front();
		q.pop();
		for(auto i:g[t.val]){
			if(i==ed){
				int tot=t.dis+1;
				if(tot==minn){
					st++;
				}
				else if(tot<minn){
					st=1;
					minn=tot;
				}
				continue;
			}
			if(vis[i])continue;
			vis[i]=1;
			q.push({i,t.dis+1});
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&(a[i]-a[i-1]!=a[i-1]-a[i-2])){
				flag=1;
			}
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					g[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		if(flag){
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					st=0;
					ed=j;
					memset(vis,0,sizeof(vis));
					minn=1e8;
					vis[i]=1;
					bfs(i,0);
					if(st==2)cnt++;
				}
			}
			cout<<cnt<<endl;
		}
		else{
			if(d<(a[n]-a[n-1])){
				cout<<0<<endl;
			}
			else{
				for(int i=1;i<=n-3;i++){
					for(int j=i+3;j<=n;j++){
						st=0;
						ed=j;
						memset(vis,0,sizeof(vis));
						minn=1e8;
						vis[i]=1;
						bfs(i,0);
						if(st==2)cnt++;
					}
				}
				cout<<cnt<<endl;
			}
		}
	}
	return 0;
}

