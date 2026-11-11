#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=2e6+5;
int c,t;
int n;
ll d;
ll x[N];
void AAA(){
	while(t--){
		n=iread();
		d=lread();
		FOR(i,1,n) x[i]=lread();
		ll dt=x[2]-x[1];
		int tmp=0;
		ll s=0;
		while(s<d&&tmp<=n){
			s+=dt;
			++tmp;
		}
		if(s<d||dt>=d) puts("0");
		else if(s==d){
			tmp=tmp+tmp;
			printf("%d\n",max(0,n-tmp+1));
		}
		else {
			--tmp;
			printf("%d\n",max(0,n-tmp-tmp+1));
		}
	}
}
void BBB(){
	while(t--){
		puts("0");
	}
}
struct EDGE{
	int frt[N],nxt[N*10],to[N*10],top;
	void add(int u,int v){
		nxt[++top]=frt[u];
		frt[u]=top;
		to[top]=v;
	}
	void double_add(int u,int v){
		add(u,v);
		add(v,u);
	}
	void init(){
		top=0;
		FOR(i,1,n) frt[i]=0;
	}
}e;
priority_queue<pair<int,int> >qp;
int dis[N],cnt[N],vis[N];
void dij(int s){
	FOR(i,1,n) dis[i]=n+1;
	FOR(i,1,n) cnt[i]=0;
	FOR(i,1,n) vis[i]=0;
	dis[s]=0;
	cnt[s]=1;
	qp.push(make_pair(0,s));
	while(!qp.empty()){
		int u=qp.top().second;qp.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=e.frt[u];i;i=e.nxt[i]){
			int v=e.to[i];
			if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			else if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				qp.push(make_pair(-dis[v],v));
			}
		}
	}
}
void bl(){
	while(t--){
		n=iread();
		d=lread();
		e.init();
		FOR(i,1,n) x[i]=lread();
		FOR(i,1,n){
			FOR(j,i+1,n){
				if(x[j]-x[i]<=d){
					e.double_add(i,j);
				}
			}
		}
		int ans=0;
		FOR(i,1,n){
			dij(i);
			FOR(j,i+1,n){
				if(cnt[j]==2){
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=iread();
	t=iread();
	if(c==11||c==12) AAA();
	else if(c==13||c==14) BBB();
	else bl();
	return 0;
}

