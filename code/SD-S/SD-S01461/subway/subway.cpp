#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
const ll M=1e18;
ll read(){
	ll f=1,sum=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=(c-'0');
		c=getchar();
	}
	return sum*f;
}
ll n,d,m,c,q,w[N],b[N],ans[1505][1505],dis[N];
vector<pair<ll,ll> > g[N];
bool vis[N];
priority_queue<pair<ll,ll> > Q;
void dij(ll st){
	for(int i=0;i<=n+m;i++){
		dis[i]=M;
		vis[i]=0;
	}
	dis[st]=0;
	vis[st]=1;
	Q.push(make_pair(0,st));
	while(Q.size()){
		ll u=Q.top().second;
		vis[u]=0;
		Q.pop();
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i].first,W=g[u][i].second;
			if(dis[v]>dis[u]+W){
				dis[v]=dis[u]+W;
				if(!vis[v]){
					vis[v]=1;
					Q.push(make_pair(-dis[v],v));
				} 
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans[st][i]=dis[i];
	}
	return ;
}
void DIJ(ll st){
	for(int i=0;i<=n+m;i++){
		dis[i]=M;
		vis[i]=0;
	}
	dis[st]=0;
	vis[st]=1;
	Q.push(make_pair(0,st));
	while(Q.size()){
		ll u=Q.top().second;
		vis[u]=0;
		Q.pop();
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i].first,W=g[u][i].second;
			if(dis[v]>dis[u]+W){
				dis[v]=dis[u]+W;
				if(!vis[v]){
					vis[v]=1;
					Q.push(make_pair(-dis[v],v));
				} 
			}
		}
	}
	return ;
}
struct ques{
	ll Q_st,Q_ed,Q_ID;
}Quer_ans[N];
ll Q_Ans[N];
bool cmp(ques QUERA,ques QUERB){
	return QUERA.Q_st<QUERB.Q_st;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	ll x=0,y=0;
	for(int i=1;i<=n;i++){
		b[i]=read();
		for(int j=1;j<=b[i];j++){
			x=read();
			y=read();
			g[x].push_back(make_pair(i+m,y));
			g[i+m].push_back(make_pair(x,y));
		}
	}
	if(c<=11){
		for(int i=1;i<=m;i++){
			dij(i);
		}
		for(int i=1;i<=q;i++){
			x=read();
			y=read();
			printf("%lld\n",ans[x][y]+w[x]+w[y]);
		}
	}
	else {
		for(int i=1;i<=q;i++){
			Quer_ans[i].Q_st=read();
			Quer_ans[i].Q_ed=read();
			Quer_ans[i].Q_ID=i;
		}
		sort(Quer_ans+1,Quer_ans+1+q,cmp);
		ll TMP_QUE=-1;
		for(int i=1;i<=q;i++){
			if(TMP_QUE!=Quer_ans[i].Q_st){
				DIJ(Quer_ans[i].Q_st);
				TMP_QUE=Quer_ans[i].Q_st;
			}	
			Q_Ans[Quer_ans[i].Q_ID]=w[Quer_ans[i].Q_st]+w[Quer_ans[i].Q_ed]+dis[Quer_ans[i].Q_ed];
		}
		for(int i=1;i<=q;i++){
			printf("%lld\n",Q_Ans[i]);
		}
	}
	return 0;
} 
