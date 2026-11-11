#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500001],s[501][20001];
struct node{
	int u,v;
};
vector<node> e[501];
struct nnn{
	int x,a,len,nn;
};
int bfs(int x,int y){
	memset(s,0,sizeof s);
	int maxn=INT_MAX;
	queue<nnn> q;
	for(int i=1;i<=n;i++){
		for(auto v:e[i]){
			int a=v.u,xx=v.v;
//				cout<<a<<i<<x<<x<<endl;
			if(a==x){
				q.push({a,i,xx,xx});
				s[i][a]=1;
			}
		}
	}
	while(!q.empty()){
		int x=q.front().x,len=q.front().len,cnt=q.front().a,ll=q.front().nn;
//		cout<<x<<" "<<cnt<<" "<<len<<" "<<ll<<endl;
		q.pop();
		if(x==y){
			maxn=min(maxn,len+ll);
		}
		for(auto v:e[cnt]){
			int a=v.u,x=v.v;
			if(s[cnt][a]==0){
				q.push({a,cnt,len,x});
				s[cnt][a]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==cnt){
				continue;
			}
			for(auto v:e[i]){
				if(v.u==x&&s[i][v.u]==0){
					s[i][v.u]=1;
					q.push({x,i,len+ll+v.v,v.v});
				}
			}
		}
	}
	return maxn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			e[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+bfs(x,y)<<endl;
	}
	return 0;
}
/*

*/
