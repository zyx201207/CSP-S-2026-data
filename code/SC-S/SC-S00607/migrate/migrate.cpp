#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int>pii;
const int mx=5e3+10;
int c,t,head[mx],cnt,sum[mx],a[mx],dist[mx],ans;
bool f,vis[mx];
struct node{
	int d,next,w;
}eg[mx];
void addedge(int u,int v,int w){
	eg[++cnt].d=v;eg[cnt].w=w;;
	eg[cnt].next=head[u];
	head[u]=cnt;
}
void djs(int st){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	memset(dist,0x3f,sizeof(dist));
	dist[st]=1;
	q.push(make_pair(0,st));
	while(!q.empty()){
		pii x=q.top();
		q.pop();
		int u=x.second;
		for(int i=head[u];i;i=eg[i].next){
			int w=eg[i].w,v=eg[i].d;
			if(dist[u]+w==dist[v])sum[v]=sum[u]+1;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v],v));
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(head,0,sizeof(head));
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(0));
		ans=cnt=0;
		int n,d;
		cin>>n>>d;
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i]; 
			addedge(a[i-1],a[i],a[i]-a[i-1]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d)addedge(a[i],a[j],a[j]-a[i]);
			}
		}
		for(int i=1;i<=n;i++){
			djs(i);
			for(int j=1;j<=n && j!=i;j++){
				if(sum[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 