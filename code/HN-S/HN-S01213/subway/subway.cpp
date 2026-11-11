#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id,u;
};
map<node,vector<node> >mp;
vector<int>q1[501];
bool operator<(node a,node b){
	return a.u>b.u;
}
int c,n,m,q,d,w[501],t[500101][101],k,s,e,vis[500101][101],ans=INT_MAX;
void dfs(int id,int u,int sum){
	if(u==e){
		ans=min(ans,sum);
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<mp[{id,u}].size();i++){
		//cout<<1;
		int w=mp[{id,u}][i].id,w1=mp[{id,u}][i].u;
		if(vis[w][w1]==1)continue;
		vis[w][w1]=1;
		if(w1==u&&w!=id){
			//cout<<w<<" "<<w1<<" "<<sum+t[id][u]+t[w][w1]<<" ";
			if(w1==e)cout<<sum+t[id][u]+t[w][w1]<<" ";
			dfs(w,w1,sum+t[id][u]+t[w][w1]);
		}else dfs(w,w1,sum);
		vis[w][w1]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
*/ 
	for(int i=1;i<=n;i++){
		cin>>k;
		int x,y,lti,ltt;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			q1[x].push_back(i);
			t[i][x]=y;
			if(j!=1){
				node a={i,lti},b={i,x}; 
				mp[a].push_back(b);
				mp[b].push_back(a);
				//cout<<i<<" "<<lti;
			}
			lti=x;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<q1[i].size();j++){
			for(int k=0;k<q1[i].size();k++){
				if(j==k)continue;
				int w=q1[i][j],w1=q1[i][k];
				node a={w,i},b={w1,i}; 
				mp[a].push_back(b);
				mp[b].push_back(a);
			}
		}
	}
	//cout<<mp[{2,2}][0].id<<mp[{2,2}][0].u<<" "<<mp[{2,2}][1].id<<mp[{2,2}][1].u<<endl;
	for(int i=0;i<mp[{2,2}].size();i++)cout<<mp[{2,2}][i].id<<mp[{2,2}][i].u<<" ";
	while(q--){
		cin>>s>>e;
		dfs(1,s,9);
		cout<<ans+13;
	}
	return 0;
}

