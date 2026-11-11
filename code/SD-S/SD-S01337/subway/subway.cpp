#include<bits/stdc++.h>
using namespace std;
int w[500025];
vector<int> l[500025];
bool vis[500025];
map<pair<int,int>,int> sj;
int c,n,m,d,q;
long long res=1000000000000000000;
void dfs(int st,int en,long long sum){
	if(st==en){
		res=min(res,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(sj[{st,i}]!=0){
			sum+=sj[{st,i}];
			for(auto t:l[i]){
				if(!vis[t]){
					vis[t]=true;
					sum+=sj[{t,i}];
					dfs(t,en,sum);
					sum-=sj[{t,i}];	
					vis[t]=false;			
				}
			}
			sum-=sj[{st,i}];
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			l[i].push_back(a);
			sj[{a,i}]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=w[x];
		dfs(x,y,0);
		ans+=res;
		ans+=w[y];
		cout<<ans<<"\n";
		res=1000000000000000000;
	}
	return 0;
}
