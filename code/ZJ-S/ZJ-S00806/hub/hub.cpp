#include<bits/stdc++.h>

using namespace std;

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}

namespace SOLVE{

const int N=1e6+5;
int n,k,fa[N],dis[N],num=0;
vi e[N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	fa[x]=y;
	num--;
	return;
}

void solve(){
	cin>>n>>k;
	rp(i,1,n)
		e[i].clear();
	rp(i,2,n){
		int u,v;
		cin>>u>>v;
		e[u].eb(v);
		e[v].eb(u);
	}
	int ans=1e9;
	rp(i,0,(1<<n)-1){
		int c=0;
		rp(j,1,n)
			if((i>>(j-1))&1)c++;
		if(c!=k)continue;
		num=0;
		rp(j,1,n)
			if((i>>(j-1))&1)fa[j]=j,num++;
		rp(j,1,n)
			for(int k:e[j])
				if(((i>>(j-1))&1)&&((i>>(k-1))&1))merge(j,k);
		if(num>2)continue;
		queue<int>q;
		rp(j,1,n)
			dis[j]=1e9;
		rp(j,1,n)
			if((i>>(j-1))&1)q.push(j),dis[j]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:e[u])
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					q.push(v);
				}
		}
		int Max=0;
		rp(j,1,n)
			gmax(Max,dis[j]);
		gmin(ans,Max);
	}
	cout<<ans<<"\n";
	return;
}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,_=1;cin>>c>>_;
	while(_--)SOLVE::solve();
	return 0;
}
