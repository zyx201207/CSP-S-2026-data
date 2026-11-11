#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],k[1000];
bool f[500010];
vector<pair<int,int>>t[1000];
map<int,vector<int>>mp;
map<pair<int,int>,int>to_w;
int bfs(int fst,int lst){    
	memset(f,0,sizeof f);
	priority_queue<pair<int,int>>q;
	q.push({fst,0});
	int ans=INT_MAX;f[fst]=1;
	while(!q.empty()){
		pair<int,int>now=q.top();q.pop();
		if(now.first==lst)ans=min(ans,now.second);
		vector<int>& temp_fast=mp[now.first];
		for(int i=0;i<temp_fast.size();++i){
			for(int k=0;k<t[temp_fast[i]].size();++k){
				int v=t[temp_fast[i]][k].first;
				if(!f[v]){
					f[v]=1;
					int w=now.second+to_w[make_pair(now.first,temp_fast[i])]+t[temp_fast[i]][k].second;
					q.push(make_pair(v,w));
				}
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int v,t_;
			cin>>v>>t_;
			t[i].push_back(make_pair(v,t_));
			mp[v].push_back(i);
			to_w[make_pair(v,i)]=t_;
		}
	}
	for(int i=1;i<=q;++i){
		int fst,lst,ans=0;
		cin>>fst>>lst;
		ans=w[fst]+w[lst];
		ans+=bfs(fst,lst);
		cout<<ans<<'\n';
	}
	return 0;
}

