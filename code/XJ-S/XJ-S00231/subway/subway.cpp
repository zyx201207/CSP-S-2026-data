#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N = 5e5+5;
int w[N];
struct station{
	int w;
	int d;
	int from,to;
	int t;
}s[N];

struct way{
	vector<int> sta;
	int s,e;
};
int bfs(int u,int v){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		
		if(s[u].to==v){
			//©ирт╣╫
			return s[u].t; 
		}
		else{
			bfs(u,v);	
		}
	}
}
int solve(int b,int e){
	//from b to e
	int ans=s[b].w+s[e].w;
	ans+=bfs(b,e);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			s[i].from=i;
			s[i].to=a;
			s[i].t=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;
} 
