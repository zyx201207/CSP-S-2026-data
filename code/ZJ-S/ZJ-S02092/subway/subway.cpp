#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=500005,maxd=25,maxq=100005;
int c,n,m,d,q;int k,t,x,y,ti,idd;
struct point{
	int w,id;int nextnum,nextid[maxd],nexttime[maxd];
}a[maxn+maxm];
long long bfs[maxm+maxn];
bool vis[maxm+maxn];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].w;a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		a[i+m].w=0;a[i+m].id=i+m;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>idd>>ti;
			a[i+m].nextid[++a[i+m].nextnum]=idd;
			a[i+m].nexttime[a[i+m].nextnum]=ti;
			a[idd].nextid[++a[idd].nextnum]=i+m;
			a[idd].nexttime[a[idd].nextnum]=ti;
		}
	}
	while(q--){
		cin>>x>>y;
		queue<point>q;int t,idt;
		memset(vis,0,sizeof vis);
		memset(bfs,100,sizeof bfs);
		q.push(a[x]);bfs[x]=0;
		while(!q.empty()){
			point f=q.front();q.pop();vis[f.id]=1;
			for(int i=1;i<=f.nextnum;i++){
				if(f.nexttime[i]+bfs[f.id]<bfs[f.nextid[i]]&&!vis[f.nextid[i]]){
					bfs[f.nextid[i]]=bfs[f.id]+f.nexttime[i];
					q.push(a[f.nextid[i]]);
				}
			}
		}
		cout<<bfs[y]+a[x].w+a[y].w<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
