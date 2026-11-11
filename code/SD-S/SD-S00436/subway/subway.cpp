#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,dis[900005],li[50005];
struct node{
	int to,t;
	friend bool operator < (node a,node b){
		return a.t<b.t;
	}
};
struct qu{
	int x,y,id;
	int ans;
}quest[900005];
bool comp1(qu a,qu b){
	return a.x<b.x;
}
bool comp2(qu a,qu b){
	return a.id<b.id;
}
vector<node>h[900005];
int dij(int s){
	memset(dis,127,sizeof dis);
	priority_queue<node>pq;
	pq.push((node){s,0});dis[s]=0;
	while(!pq.empty()){
		int x=pq.top().to,k=pq.top().t;
		pq.pop();
		if(k>dis[x])continue;
		for(int i=0;i<h[x].size();i++){
			int to=h[x][i].to;
			if(dis[to]>dis[x]+h[x][i].t || dis[to]==-1){
				dis[to]=dis[x]+h[x][i].t;
				pq.push((node){to,dis[to]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		int t;
		scanf("%lld",&t);
		h[i].push_back((node){m+i,t});
		h[m+i].push_back((node){i,t});
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int o=1;o<=k;o++){
			int b;
			scanf("%lld%lld",&li[o],&b);
			h[li[o]+(i+1)*m].push_back((node){m+li[o],b});
			h[m+li[o]].push_back((node){li[o]+(i+1)*m,b});
		}
		for(int o=1;o<=k;o++){
			for(int j=o+1;j<=k;j++){
				h[li[o]+(i+1)*m].push_back((node){li[j]+(i+1)*m,0});
				h[li[j]+(i+1)*m].push_back((node){li[o]+(i+1)*m,0});
			}
		}
    }
    for(int i=1;i<=q;i++){
    	int x,y;
    	scanf("%lld%lld",&x,&y);
    	quest[i].x=x;
    	quest[i].y=y;
    	quest[i].id=i;
	}
	sort(quest+1,quest+q+1,comp1);
	for(int i=1;i<=q;i++){
		if(i==1 || quest[i].x!=quest[i-1].x){
			dij(quest[i].x);
		}
		quest[i].ans=dis[quest[i].y]; 
	}
	sort(quest+1,quest+q+1,comp2);
	for(int i=1;i<=q;i++)
	  printf("%lld\n",quest[i].ans);
	return 0; 
}
