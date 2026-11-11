#include <bits/stdc++.h>
using namespace std;
int c,T,n,t[5005],ans;
long long x[5005],d;
long long tag[5005];
vector<int> a[5005];
deque<int> p;
queue<int> q;
void bfs(const int &root){
	memset(t,0,sizeof(t));
	memset(tag,0x3f,sizeof(tag));
	q.push(root);
	tag[root]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(const auto &v:a[u]){
			if(tag[v]==tag[u]+1) ++t[v];
			else if(tag[v]>tag[u]+1){
				tag[v]=tag[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(t[i]==1) ++ans;
	}
	/*cout<<root<<":\n";
	for(int i=1;i<=n;++i){
		cout<<tag[i]<<" "<<t[i]<<"\n";
	}*/
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		p.clear();
		for(int i=1;i<=n;++i) a[i].clear();
		//memset(t,0,sizeof(t));
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		p.push_back(1);
		for(int i=2;i<=n;++i){
			while(!p.empty()&&x[i]-x[p.front()]>d) p.pop_front();
			for(auto v:p){
				a[v].push_back(i);
			}
			p.push_back(i);
		}
		//
		/*
		for(int i=1;i<=n;++i){
			cout<<i<<":";
			for(auto v:a[i]) cout<<v<<" ";
			cout<<"\n";
		}*/
		//
		for(int i=1;i<=n;++i){
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}