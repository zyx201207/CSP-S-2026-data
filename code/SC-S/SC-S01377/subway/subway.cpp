#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=INT_MAX;
int w[5005];
int a[5005][505],t[5005][505];
bool vis[5005][5005][2];
struct st{
	int pos,z,val,num;//num:铁路的编号 (z=1) 
};
void bfs(int s,int e){
	queue<st>q;
	st p;
	p.pos=s,p.num=0,p.val=0,p.z=0;
	q.push(p);
	vis[s][0][0]=1;
	while(!q.empty()){
		st o=q.front();
		q.pop();
		if(o.pos==e&&o.z==1){
			ans=min(ans,o.val);
			return;
		}
		if(o.z==0){
			for(int i=1;i<=n;i++){
				if(a[i][o.pos]==1&&!vis[o.pos][i][1]){
					st ns;
					ns.pos=o.pos,ns.z=1,ns.num=i,ns.val=o.val+t[i][ns.pos];
					vis[ns.pos][ns.num][ns.z]=1;
					q.push(ns);
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				if(j==o.pos||vis[j][o.num][1]) continue;
				st ns;
				ns.pos=j,ns.z=1,ns.num=o.num,ns.val=o.val;
				vis[j][o.num][1];
				q.push(ns);
			}
			if(!vis[o.pos][0][0]){
				st ns;
				ns.pos=o.pos,ns.z=0,ns.num=0,ns.val=o.val+t[o.num][o.pos];
				vis[o.pos][0][0]=1;
				q.push(ns);
			}
			
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(t,0,sizeof(t));
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int f;
			cin>>f;
			a[i][f]=1;
			cin>>t[i][f];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		bfs(l,r);
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}