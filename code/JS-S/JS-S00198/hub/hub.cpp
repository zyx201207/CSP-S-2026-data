#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,k,dis[1000005],fa[1000005],dep[1000005],md[1000005],rt1,rt2,t1,t2,col[1000005];
vector<int>g[1000005];
void dfs(int x,int dt,int lst){
	if(dis[x]!=-1)return;
	dis[x]=dt;
	fa[x]=lst;
	for(int i=0;i<g[x].size();i++)
		dfs(g[x][i],dt+1,x);
}
void dfs1(int x,int dt,int lst){
	if(x==t2)return;
	if(col[x]!=0)return;
	col[x]=1;
	dis[x]=dt;
	fa[x]=lst;
	for(int i=0;i<g[x].size();i++)
		dfs1(g[x][i],dt+1,x);	
}
void dfs2(int x,int dt,int lst){
	if(x==t1)return;
	if(col[x]!=0)return;
	col[x]=2;
	dis[x]=dt;
	fa[x]=lst;
	for(int i=0;i<g[x].size();i++)
		dfs2(g[x][i],dt+1,x);	
}
void dfss(int coll,int x,int lst){
	if(col[x]!=coll)return;
	if(dep[x]!=0)return;
	dep[x]=dep[lst]+1;
	fa[x]=lst;
	md[x]=dep[x];
	for(int i=0;i<g[x].size();i++){
		dfss(coll,g[x][i],x);
		if(col[g[x][i]]==col[x])md[x]=max(md[x],md[g[x][i]]);
	}
}
priority_queue<pair<int,int> >q;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int I=0;I<t;I++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
			dis[i]=INT_MAX;
			col[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1,0,1);
		int kkk=1;
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[kkk])kkk=i;
		for(int i=1;i<=n;i++)
			dis[i]=-1;
		dfs(kkk,0,kkk);
		int ttt=1;
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[ttt])ttt=i;
		int ddd=0,xxx=ttt;
		while(fa[xxx]!=xxx){
			xxx=fa[xxx];
			ddd++;
		}
		ddd=(ddd+1)>>1;
		xxx=ttt;
		for(int i=1;i<ddd;i++)
			xxx=fa[xxx];
		t1=xxx;t2=fa[xxx];
		dfs1(t1,0,t1);
		dfs2(t2,0,t2);
		int kkk1=0,kkk2=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[kkk1]&&col[i]==1)kkk1=i;
			else if(dis[i]>dis[kkk2]&&col[i]==2)kkk2=i;
		for(int i=1;i<=n;i++)
			col[i]=0;
		dfs1(kkk1,0,kkk1);
		dfs2(kkk2,0,kkk2);
		int ttt1=1,ttt2=1;
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[ttt1]&&col[i]==1)ttt1=i;
			else if(dis[i]>dis[ttt2]&&col[i]==2)ttt2=i;
		//for(int i=1;i<=n;i++)
		//	cout<<col[i]<<'\n';
		int xxx1=dis[ttt1]>>1;rt1=ttt1;
		for(int i=0;i<xxx1;i++)rt1=fa[rt1];
		int xxx2=dis[ttt2]>>1;rt2=ttt2;
		for(int i=0;i<xxx2;i++)rt2=fa[rt2];
		for(int i=1;i<=n;i++)
			dep[i]=md[i]=0;
		//cerr<<rt1<<' '<<rt2<<'\n';
		dfss(1,rt1,rt1);
		dfss(2,rt2,rt2);			
		k-=2;
		for(int i=0;i<g[rt1].size();i++)
			if(col[g[rt1][i]]==1)q.push(mp(md[g[rt1][i]]-1,g[rt1][i]));
		for(int i=0;i<g[rt2].size();i++)
			if(col[g[rt2][i]]==2)q.push(mp(md[g[rt2][i]]-1,g[rt2][i]));
		//for(int i=1;i<=n;i++)
		//	cerr<<dep[i]<<' ';
		while(k--&&!q.empty()){
			pair<int,int>tt=q.top();
			q.pop();
			for(int i=0;i<g[tt.se].size();i++)
				if(dep[g[tt.se][i]]>dep[tt.se]&&col[g[tt.se][i]]==col[tt.se])q.push(mp(md[g[tt.se][i]]-dep[tt.se],g[tt.se][i]));
		}
		if(q.empty())cout<<0<<'\n';
		else cout<<q.top().fi<<'\n';
	}
	return 0;
}