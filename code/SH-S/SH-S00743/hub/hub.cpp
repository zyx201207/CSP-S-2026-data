#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int fa[300009];
pair<int,int>dep[300009];
bool vis[300009];
vector<int>mp[300009]; 
void dfs1(int x){
	for(int i:mp[x]){
		if(vis[i])continue;
		vis[i]=1;
		fa[i]=x;
		dep[i]=make_pair(dep[x].first+1,i);
		dfs1(i);
	}
}
bool check(int x){
	int is_ok[300009]={};
	int ss=n;
	int cnt=0;
	for(int i = n;i >= 1;i --){
		if(is_ok[dep[i].second])continue;
		cnt++;
		int tmp=dep[i].second;
		for(int j = 0;j < x;j ++){
			tmp=fa[tmp];
		}
		if(is_ok[tmp]==0)ss--;
		is_ok[tmp]=x+1;
		queue<int>que;
		que.push(tmp);
		while(!que.empty()){
			int nw=que.front();
			que.pop();
			for(int j:mp[nw]){
				if(is_ok[j]<is_ok[nw]-1&&is_ok[nw]-1){
					if(is_ok[j]==0)ss--;
					is_ok[j]=is_ok[nw]-1;
					que.push(j);
				}
			}
		}
	}
	return ss==0&&cnt<=k;
}
void solve(){
	for(int i = 0;i < 300009;i ++){
		dep[i]=make_pair(0,0);
		mp[i].clear();
		vis[i]=0;
	}
	cin>>n>>k;
	for(int i = 1;i < n;i ++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	fa[1]=1;
	dfs1(1);
	sort(dep+1,dep+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<r-1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 0;i < t;i ++)
		solve(); 
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
