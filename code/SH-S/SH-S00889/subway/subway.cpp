#include<bits/stdc++.h>
using namespace std;
struct node{
	int dis,id,ans;
	friend operator<(node a,node b){
		return a.dis>b.dis;
	}
};
int n,m,d,q;
long long w[500005];
vector<node>b[505];
vector<node>a[500005];
bool flag[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			b[i].push_back({t,x,t});
			for(int l=0;l<b[i].size()-1;l++){
				a[b[i][l].id].push_back({t+b[i][l].dis,x,t+b[i][l].dis});
			}
		}
	}
	
	while(q--){
		memset(flag,0,sizeof(flag));
		int st,en;
		cin>>st>>en;
		priority_queue<node>Q;
		Q.push({0,st,0});
		flag[st]=1;
		while(!Q.empty()){
			node u=Q.top();
			Q.pop();
			if(u.id==en){
				cout<<w[st]+w[en]+u.ans<<endl;
				break;
			}
			for(int i=0;i<a[u.id].size();i++){
				if(flag[a[u.id][i].id])continue;
				Q.push(a[u.id][i]);
			}
		}
		
	}
	return 0;
}
