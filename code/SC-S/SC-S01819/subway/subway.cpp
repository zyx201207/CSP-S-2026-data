#include<bits/stdc++.h>
using namespace std;
using ll=int;

struct node{
	ll id;
	ll s;
};

ll c,N,M,d,q;
ll w[500005];
vector<node>D[500505];//线路:编号+5e5;

int ans[20005][20005];

void dijstla(int u,int v){
	bool vis[500505];
	ll s[500505];
	for(int i=0;i<=500505;i++)vis[i]=0,s[i]=2000000000;
	s[u]=0;
	int now=u;
	while(now){
		ans[u][now]=s[now];
		ans[now][u]=s[now];
		vis[now]=1;
		if(now==v){
			cout<<s[now]+w[u]+w[v]<<'\n';
			break;
		}
		ll next=0;
		for(auto o:D[now]){
			if(vis[o.id])continue;
			s[o.id]=min(s[o.id],s[now]+o.s);
		}
		for(int i=1;i<=500505;i++){
			if((s[i]<=s[next]&&vis[i]==0))next=i;
		}
		
		
		now=next;
		
		
//		cout<<now<<'\n';
	}
}

void dijstlaft(int u,int v){
	bool vis[500505];
	ll s[500505];
	for(int i=0;i<=500505;i++)vis[i]=0,s[i]=1000000000;
	s[u]=0;
	int now=u;
	while(now){
		priority_queue<int,vector<int>,greater<int>>q;
		ans[u][now]=s[now];
		ans[now][u]=s[now];
		vis[now]=1;
		if(now==v){
			cout<<s[now]+w[u]+w[v]<<'\n';
			break;
		}
		ll next=0;
		for(auto o:D[now]){
			if(vis[o.id])continue;
			s[o.id]=min(s[o.id],s[now]+o.s);
			q.push(o.id);
		}
		next=q.top();
		now=next;
		
		
//		cout<<now<<'\n';
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	bool ft=1,tt=0;
	
	cin>>c>>N>>M>>d>>q;
	for(ll i=1;i<=M;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=N;i++){
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			D[500000+i].push_back({a,t});
			D[a].push_back({500000+i,t});
			if(tt==0)tt=t;
			if(j!=0&&tt!=t)ft=0;
		}
	}
	
//	for(int i=1;i<=5;i++){
//		cout<<i<<' ';
//		for(auto o:D[i]){
//			cout<<o.id<<' ';
//		}
//		cout<<'\n';
//	}
	if(ft){
		while(q--){
			int u,v;
			cin>>u>>v;
			if(ans[u][v]!=0){
				cout<<ans[u][v]<<'\n';
			}else
				dijstlaft(u,v);
		}
		return 0;
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(ans[u][v]!=0){
			cout<<ans[u][v]<<'\n';
		}else
			dijstla(u,v);
	}
	return 0;
}