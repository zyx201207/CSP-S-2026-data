#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
struct node{
	int a,id;
	long long t,op;
}a[500005];
int k[505];
struct P{
	int a,id;
	long long t,ti;
};
vector<node> g[500005];
long long ti[500005];
bool f[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j].a>>a[j].t;
		}
		for(int j=1;j<=k[i];j++){
			for(int kk=1;kk<=k[i];kk++){
				if(kk==j)continue;
				node twt;
				twt.t=a[j].t;
				twt.a=a[kk].a;
				twt.id=i;
				twt.op=a[kk].t;
				g[a[j].a].push_back(twt);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)ti[i]=LONG_LONG_MAX;
		queue<P> que;
		P twt;
		twt.a=x,twt.id=0,twt.t=0,twt.ti=w[x];
		que.push(twt);
		ti[x]=w[x];
		long long ans=LONG_LONG_MAX;
		while(!que.empty()){
			twt=que.front();
			que.pop();
			int tq=twt.a,tid=twt.id;
			long long la=twt.t,dis=twt.ti;
			if(dis!=ti[tq])continue;
			if(y==tq){
				ans=min(ans,dis+la+w[y]);
				continue;
			}
			for(node v:g[tq]){
				long long now;
				if(v.id!=tid)now=dis+v.t+la;
				else now=dis;
				if(now<ti[v.a]){
					ti[v.a]=now;
					twt.a=v.a;
					twt.t=v.op;
					twt.id=v.id;
					twt.ti=now;
					que.push(twt);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/