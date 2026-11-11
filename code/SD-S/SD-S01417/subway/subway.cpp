//SQKS
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int>bp;
int C,m,n,K,q;
int e[1000010],ne[1000010],h[1000010],idx;
ll a[500010];
ll w[1000010];
void add(int a,int b,ll c){
	e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
}
bool vs[500520];
ll d[500520];
ll dis[3510][3510];
void sol(int x){
	priority_queue<bp,vector<bp>,greater<bp> >q;
	memset(d,0x3f,sizeof d);
	memset(vs,0,sizeof vs);
	d[x]=0;
	q.push({0,x});
	while(!q.empty()){
		bp t=q.top();q.pop();
		x=t.second;
		if(vs[x])continue;
		vs[x]=1;
		for(int i=h[x];i;i=ne[i]){
			int j=e[i];
			if(d[j]>d[x]+w[i]){
				d[j]=d[x]+w[i];
				q.push({d[j],j});
			}
		}
	}
}
void soll(int x){
	priority_queue<bp,vector<bp>,greater<bp> >q;
	memset(dis[x],0x3f,sizeof dis[x]);
	memset(vs,0,sizeof vs);
	dis[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		bp t=q.top();q.pop();
		int xx=t.second;
		if(vs[xx])continue;
		vs[xx]=1;
		for(int i=h[xx];i;i=ne[i]){
			int j=e[i];
			if(dis[x][j]>dis[x][xx]+w[i]){
				dis[x][j]=dis[x][xx]+w[i];
				q.push({dis[x][j],j});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>m>>n>>K>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1+n;i<=m+n;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			int x;
			ll c;
			cin>>x>>c;
			add(i,x,c),add(x,i,c);
		}
	}
	if(n<=3010){
	/*	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0x3f3f3f3f3f3f3f3f;
			}
		}*/
		for(int i=1;i<=n;i++)soll(i);
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<a[l]+a[r]+dis[l][r]<<"\n";
		}
		return 0;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		sol(l);
		cout<<a[l]+a[r]+d[r]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
