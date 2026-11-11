#include<bits/stdc++.h>
using namespace std;
struct node{
	long long to,val;
	bool friend operator <(node a,node b){
		return a.val>b.val;
	}
};
long long n,m,c,d,q,w[500050],k,to[500050],ti[500050],l,r,cnt=1,vis[500050],dis[500050];
priority_queue<node> qu;
vector<node> sub[500010];
void dij(int x){
	while(!qu.empty()){
		qu.pop();
	}
	for(int i=1;i<=m*(cnt+1);i++){
		dis[i]=1e9+10;
		vis[i]=0;
	}
	dis[x]=0;
	qu.push({x,0});
	while(!qu.empty()){
		node tmp=qu.top();
		qu.pop();
		if(vis[tmp.to]){
			continue;
		}
		vis[tmp.to]=true;
		for(auto i:sub[tmp.to]){
			if(dis[i.to]>dis[tmp.to]+i.val){
				dis[i.to]=dis[tmp.to]+i.val;
				//cout<<i.to<<" "<<dis[i.to]<<endl;
				qu.push({i.to,i.val});
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sub[i].push_back({i+m,w[i]});
		sub[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			cin>>to[j]>>ti[j];
			sub[to[j]].push_back({to[j]+cnt*m,ti[j]});
			sub[to[j]+cnt*m].push_back({to[j],ti[j]});
		}
		for(int j=1;j<=k;j++){
			if(j<k){
				sub[to[j]+cnt*m].push_back({to[j+1]+cnt*m,0});
		    	sub[to[j+1]+cnt*m].push_back({to[j]+cnt*m,0});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		dij(l+m);
		cout<<dis[r+m]<<endl;
	}
	/*
	for(auto i:sub[20]){
		cout<<i.to<<" ";
	}
	*/
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/