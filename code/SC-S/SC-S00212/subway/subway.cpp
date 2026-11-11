#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],vis[1100];
struct stin{
	int line,t,nw;
};
struct node{
	int time[505];
	vector<int >to,id; 
}st[1005];
int bfs(int str,int ed){
	queue<stin > q;
	stin r;
	r.line=0;
	r.t=0;
	r.nw=str;
	q.push(r);
	int ans=1e9;
	while(q.size()){
		stin now=q.front();
		q.pop();
		if(now.nw==ed){
			ans=min(ans,now.t+st[now.nw].time[now.line]);
			continue;
		}
		for(int i=0;st[now.nw].id.size()>i;i++){
			int nid=st[now.nw].id[i];
			int nto=st[now.nw].to[i];
			if(nid!=now.line) now.t+=st[now.nw].time[nid]+st[now.nw].time[now.line];
			//cout<<now.nw<<" "<<nid<<" "<<st[now.nw].time[nid]<<" "<<st[now.nw].time[now.line]<<endl;
			if(vis[nto]<=now.t) continue;
			vis[nto]=now.t;
			stin r;
			r.line=nid;
			r.t=now.t;
			r.nw=nto;
			q.push(r);
		}
		//cout<<now.nw<<""<<now.t<<endl;
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;m>=i;i++)
		scanf("%d",&w[i]);
	for(int i=1;n>=i;i++){
		scanf("%d",&k[i]);
			int nx=0,b,tt;
		for(int j=1;k[i]>=j;j++){
			scanf("%lld%lld",&b,&tt);
			if(nx!=0) {
				st[b].to.push_back(nx);
				st[nx].to.push_back(b);
				st[b].id.push_back(i);
				st[nx].id.push_back(i);
			}
			st[b].time[i]=tt;
			nx=b;
		}
	}
	//cout<<st[2].time[1]<<" "<<st[2].time[2]<<endl;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(vis,0x3f,sizeof(vis));
		printf("%lld\n",w[x]+w[y]+bfs(x,y));
	}
	return 0;
}