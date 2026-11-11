#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,di,ad[1000003],s,l,r,o;
int f[1000003],head[1000003],k=1;
int d[1000003],beg,en,oth;
struct node{
	int v,w,next;
}e[505];
void add(int x,int y,int z){
	e[k].v=y;
	e[k].w=z;
	e[k].next=head[x];
	head[x]=k++;
}
void dijkstra(int s){
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(head,-1,sizeof(head));
	typedef pair<int,int> p;
	priority_queue<int,vector<p>,greater<p> > q;
	d[s]=0;
	q.push({d[s],s});
	while(!q.empty()){	
		int u=q.top().second;
		q.pop();
		if(f[u]) continue;
		f[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int xx=e[i].v;
			if(d[u]+e[i].w<d[xx]){
				d[xx]=d[u]+e[i].w;
				q.push({d[xx],xx});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);      
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>di>>t;
	oth=n;
	for(int i=1;i<=n;i++) cin>>ad[i];
	for(int i=1;i<=m;i++){
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>r>>o;
			if(e[l].v!=0){
				add(++oth,r,o);
				add(r,oth,o);
			}
			add(l,r,o);
			add(r,l,o);
			l=r;
		}
	}
	while(t--){
		cin>>beg>>en;
		dijkstra(0);
		cout<<d[en]<<"\n";
	}
	return 0;
}

