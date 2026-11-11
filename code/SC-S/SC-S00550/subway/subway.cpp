#include<bits/stdc++.h>
using namespace std;
long long w[600];
struct node{
	long long a,t,lu;
}ma[600];
bool use[600];
struct node1{
	long long whe,lu;
};
struct node2{
	long long whe,tim,lu;
};
vector<node1>mm[600];
long long bfs(long long x,long long y){
	queue<node2>q;
	q.push({x,0,mm[x][x].lu});
	use[x]=1;
	while(!q.empty()){
		node2 temp=q.front();q.pop();
		if(temp.whe==y) return temp.tim;
		for(auto v:mm[temp.whe])
			if(!use[v.whe]){
				if(v.lu!=temp.lu) temp.tim=temp.tim+ma[temp.whe].t+ma[v.whe].t;
				else temp.tim+=ma[v.whe].t;
				q.push({v.whe,temp.tim});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
			cin>>ma[j].a>>ma[j].t,ma[j].lu=k;
	    for(long long j=1;j<=k;j++){
	    	for(long long h=1;h<=k;h++)
	        	if(j!=h) mm[ma[j].a].push_back({ma[h].a,k});
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+bfs(x,y)<<'\n';
	}
	return 0;
}