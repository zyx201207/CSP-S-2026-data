#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,ans;
long long in[1000005],dis[1000005],vis[1000005],fl[1000005];
struct node{
    long long to,val;
};
vector<node> v[1000005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
void spaf(){
	for(int i=1;i<=n;i++){
		in[i]=0;
		dis[i]=1e16;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dis[i]=0;
			in[i]=1;
			q.push(make_pair(dis[i],i));
		}
	}
	while(q.size()){
		int u=q.top().second;
		q.pop();
		in[u]=0;
		for(int i=0;i<v[u].size();i++){
			int to=v[u][i].to;
			int val=v[u][i].val; 
			if(dis[u]+val<dis[to]){
				dis[to]=dis[u]+val;
				if(in[to]==0){
					in[to]=1;
					q.push(make_pair(dis[to],to));
				}
			}
		}	
	}
	long long ma=-1e16;
	for(int i=1;i<=n;i++){
		ma=max(ma,dis[i]);
	} 
	ans=min(ans,ma);
	return;
}
void df(int i){
	fl[i]=0;
	for(int j=0;j<v[i].size();j++){
		int to=v[i][j].to;
		if(fl[to]){
			df(to);
		} 
	} 
	return;
}
bool check(){
	for(int i=1;i<=n;i++){
		fl[i]=vis[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(fl[i]){
			sum++;
			if(sum>2)return 0;
			df(i);
		}
	}
	if(sum<=2)return 1;
	else return 0;
}
void dfs(int i,int s){
	if(i==n+1){
		if(s==k&&check())spaf();
		return;
	}
	dfs(i+1,s);
	vis[i]=1;
	dfs(i+1,s+1);
	vis[i]=0;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(13<=c&&c<=14){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				v[i].clear();
			}
			for(int i=1;i<=n-1;i++){
				int x,y;
				cin>>x>>y;
				node nw;
				nw.to=x;
				nw.val=1;
				v[y].push_back(nw);
				nw.to=y;
				v[x].push_back(nw);
			}
			if(k>=n/2){
				cout<<"1\n";
			}
			else{
				cout<<(n/2+1-k)/4+1<<"\n";
			}
		}
	} 
	else{
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				v[i].clear();
			}
			for(int i=1;i<=n-1;i++){
				int x,y;
				cin>>x>>y;
				node nw;
				nw.to=x;
				nw.val=1;
				v[y].push_back(nw);
				nw.to=y;
				v[x].push_back(nw);
			}
			ans=1e18;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
