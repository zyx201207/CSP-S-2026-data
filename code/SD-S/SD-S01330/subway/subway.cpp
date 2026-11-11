#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[5005];
long long k[5005];
struct Node{
	long long v,w;
	bool operator<(const Node&y)const{
		return w>y.w;
	}
};
priority_queue<Node> que;
long long dis[405][405];
long long v[405][405];
long long t[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long o;
			cin>>v[j][i]>>o;
			t[v[j][i]][i]=o;
		}
	}
	long long s,l;
	while(q--){
		while(!que.empty()){
			que.pop();
		}
		cin>>s>>l;
		memset(dis,-1,sizeof dis);
		for(int i=1;i<=n;i++){
			dis[s][i]=0;
		}
		que.push(Node{s,0});
		while(!que.empty()){
			Node x=que.top();
			que.pop();
			if(x.v==l) break;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]==-1){
						dis[i][j]=dis[x.v][j]+t[i][j]+t[x.v][j]+w[x.v]*2+w[i];
						que.push(Node{i,dis[i][j]});
					}
				}
			}
		}
		long long ans=2e18;
		for(int i=1;i<=n;i++){
			ans=min(ans,dis[l][i]+t[l][i]+t[s][i]);
		}
		cout<<ans+w[l]<<endl;
	}
	return 0;
}
