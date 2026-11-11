#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=500+5;
struct w{
	int to,ne,val,kos=0;
}edge[M*20];
struct eee{
	int id,kind;
}node[M*20];
int nodcnt;
int head[M*20],tot;
vector<int> sub[M];
int T,n,m,d,q;
int subcnt[M],subys[M][25];
void add(int x,int y,int t){
	edge[++tot].to=y;
	edge[tot].val=t;
	edge[tot].ne=head[x];
	head[x]=tot;
	return ;
}
int jia[M];
map<pair<int,int> , int> mp;
map<pair<int,int> , int> dist;
map<pair<int,int> , bool> flag;
map<pair<int,int> , int> dis;
int num[M];
typedef pair<int,int> pii;
//dij中的节点编号均为nodcnt 
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[{s,s}]=0;
	//flag[{s,s}]=1;
	q.push({0,s});
	while(q.size()){
		pii f=q.top();
		q.pop();
		int id=f.second,kind=node[f.second].kind;
		if(flag[{s,id}]) continue;
		flag[{s,id}]=1;
		if(kind==0){
			for(int i=head[id];i;i=edge[i].ne){
				int j=edge[i].to,val=edge[i].val;
				//if(flag[{s,j}]) continue;
				if(!dis[{s,j}]) dis[{s,j}]=1e9;
				//flag[{s,j}]=1;
				if(dis[{s,j}]>dis[{s,id}]+val){
					dis[{s,j}]=dis[{s,id}]+val;
					q.push({dis[{s,j}],j});
				}
			}
		}
		else{
			for(int i=head[id];i;i=edge[i].ne){
				int j=edge[i].to,val=edge[i].val;
				//if(flag[{s,j}]) continue;
				if(!dis[{s,j}]) dis[{s,j}]=1e9;
				//flag[{s,j}]=1;
				int kind2=node[j].kind;
				//cout<<node[f.second].id<<" "<<node[j].id<<" "<<val<<endl;
				if(kind==kind2){
					if(dis[{s,j}]>dis[{s,id}]){
						dis[{s,j}]=dis[{s,id}];
						q.push({dis[{s,j}],j});
					}
				}else{
					if(dis[{s,j}]>dis[{s,id}]+val){
						dis[{s,j}]=dis[{s,id}]+val;
						q.push({dis[{s,j}],j});
					}
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&T,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&jia[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int a,t;
		int last;
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			if(!mp[{a,0}]){
				mp[{a,0}]=1;
				node[++nodcnt].id=a;
				node[nodcnt].kind=0;
				num[a]=nodcnt;
			}
			if(!mp[{a,i}]){
				mp[{a,i}]=1;
				node[++nodcnt].id=a;
				node[nodcnt].kind=i;
			}
			add(nodcnt,num[a],t);
			add(num[a],nodcnt,t);
			dist[{num[a],nodcnt}]=t;
			add(num[a],nodcnt,t);
			for(auto x:sub[a]){
				//cout<<"131313";
				//cout<<dist[{a,x}]+dist[{a,nodcnt}]<<endl;
				add(x,nodcnt,dist[{num[a],x}]+dist[{num[a],nodcnt}]);
				add(nodcnt,x,dist[{a,x}]+dist[{a,nodcnt}]);
			}
			if(j>=2){
				add(nodcnt,last,0);
				add(last,nodcnt,0);
				//cout<<node[last].kind<<" "<<node[nodcnt].kind<<endl;
			}
			sub[a].push_back(nodcnt);
			last=nodcnt;
		}
	}
//	for(int i=1;i<=m*20;i++){
//		for(int j=1;j<=m*20;j++){
//			dis[{i,j}]=1e9;
//		}
//	}
	for(int i=1;i<=m;i++){
		dij(num[i]);
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		printf("%d\n",dis[{num[x],num[y]}]+jia[x]+jia[y]);
	}
	return 0;
}