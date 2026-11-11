#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,Q=1e5+5;
int c,n,m,d,q,w[M],sk[M],st[M],a[M],t[M],x,y;
int tot=0,head[505],ne[M],ver[M],val[M],vis[M];
void add(int x,int y,int idx){
	ne[++tot]=head[x];
	ver[tot]=y;
	head[x]=tot;
	val[tot]=idx;
	return;
}
struct node{
	int x,sum,idx;
	bool operator<(const node&p)const{
		return sum>p.sum;
	}
};
void bfs(int beg,int end){
	priority_queue<node> q; 
	q.push({beg,0,0});
	while(!q.empty()){
		node tmp=q.top();q.pop();
		if(tmp.x==n+1){
			cout<<tmp.sum<<"\n"; 
			return;
		}
		if(tmp.x==end){
			tmp.sum+=t[tmp.idx]+w[tmp.x];
			q.push({n+1,tmp.sum,0});
		}
		else{
			for(int i=head[tmp.x];i;i=ne[i]){
				int y=ver[i];
				if(a[tmp.idx+1]==y){
					q.push({y,tmp.sum,val[i]});
				}
				else{
					q.push({y,tmp.sum+t[tmp.idx]+t[val[i]],val[i]});
				}
			}
		}
	} 
	cout<<"0";
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&sk[i]);
		sk[i]+=sk[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=sk[i-1]+1;j<=sk[i];j++){
			scanf("%d%d",&a[j],&t[j]);
			add(a[j-1],a[j],j);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		bfs(x,y);
	}
	return 0;
} 
