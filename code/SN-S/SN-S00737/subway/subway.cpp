#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id;
	int time;
	bool operator < (node x)const{
		return time>x.time;
	}
};
int c,st,en;
int n,m,d,q,w[26][512345];
vector<node> v[26][600000];
bool vv[26][600000];
int bfs(){
	priority_queue<node> q;
	q.push({st,w[c][st]});
	vv[c][st]=1;
	while(q.size()){
		node h=q.top();
		int id=h.id;
//		cout<<id<<endl;
		q.pop(); 
		if(id==en) return h.time;
		for(int i=0;i<v[c][id].size();i++){
			node ne=v[c][id][i];
			if(ne.id!=id){
				q.push({ne.id,h.time+ne.time});
//				vv[c][ne.id]=1;
			}
		}
	}
}
void Q_Q(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[c][i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int y,t;
			cin>>y>>t;
			v[c][m+i].push_back({y,t});
			v[c][y].push_back({m+i,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		printf("%lld\n",bfs()+w[c][en]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c) Q_Q();
//	priority_queue<node> q;
//	q.push({1,2});
//	q.push({2,112});
//	cout<<q.top().id; 
} 
