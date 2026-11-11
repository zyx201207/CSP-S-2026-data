#include<bits/stdc++.h>
using namespace std;
const int maxn  = 5e5+505;
#define ll long long
ll c,n,m,d,T;
ll w[maxn];
ll k[505];
//ll a[505][25];
//ll t[505][25];
struct node{
	ll v,w,pre;
}t[maxn<<1];
struct noe{
	int id,sum;
	bool operator < (noe y)const{
		return sum>y.sum;
	}
};
ll on;
ll head[maxn];
void pu(ll u,ll v,ll w){
	t[++on].pre = head[u];
	t[on].v = v;
	t[on].w = w;
	head[u] = on;
}
bool book[maxn];
void cl(){
	for(ll i=1;i<=m+n;i++){
		book[i]=0;
	} 
}
void dij(ll st,ll en){
	priority_queue<noe> q;
	q.push({st,0});
	cl();
	while(!q.empty()){
		noe p = q.top();
		q.pop();
		if(book[p.id]==1)continue;
		book[p.id]=1;
		if(p.id==en){
			cout<<p.sum+w[st]+w[en]<<endl;
			while(!q.empty())q.pop();
			return;
		}
		for(ll i = head[p.id];i;i=t[i].pre){
			ll v = t[i].v;
			ll w = t[i].w;
			if(book[v]==0){
				q.push({v,p.sum+w});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
		//	cin>>a[i][j];
		//	cin>>t[i][j];
			int v,w;
			cin>>v>>w;
			pu(m+i,v,w);
			pu(v,m+i,w);
		}
	}
	while(T--){
		ll x,y;
		cin>>x>>y;
		dij(x,y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}