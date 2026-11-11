#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct data{
	ll tox,toy,jl;
	bool operator > ( const data& a ) const { return jl > a.jl; }
};
struct node{
	ll op,ed,x,ans;
}que[100010];
ll T,n,m,di,qu;
ll d[500010][23];
bool vis[500010][23];
ll read(){
	ll f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
vector<vector<data> > v[500010];//*0:exit *1:st *n:car
vector<data> a;
void build(ll x1,ll y1,ll x2,ll y2,ll z){
	v[x1][y1].push_back({x2,y2,z});
	v[x2][y2].push_back({x1,y1,z});
}
priority_queue< data , vector<data> ,greater<data> > q;
void dj(ll s){
	memset(vis,0,sizeof(vis));
	memset(d,0x7f,sizeof(d));
	d[s][0]=0;
	while(!q.empty()) q.pop();
	q.push({s,0,0});
	while(!q.empty()){
		ll fromx=q.top().tox,fromy=q.top().toy;
		q.pop();
		if(vis[fromx][fromy]) continue;
		vis[fromx][fromy]=1;
		for(ll i=0;i<v[fromx][fromy].size();i++){
			ll tox=v[fromx][fromy][i].tox,toy=v[fromx][fromy][i].toy,jl=v[fromx][fromy][i].jl;
			if(d[tox][toy]>d[fromx][fromy]+jl){
				d[tox][toy]=d[fromx][fromy]+jl;
				q.push({tox,toy,d[tox][toy]});
			}
		}
	}
	return;
}
bool cmp(node a,node b){
	return a.op<b.op;
}
bool cmp1(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>T>>n>>m>>di>>qu;
	for(ll i=1;i<=m;i++){
		ll t=read();
		v[i].push_back(a);
		v[i].push_back(a);
		build(i,0,i,1,t);
	}
	for(ll i=1;i<=n;i++){
		ll k=read();
		ll last=0;
		for(ll j=1;j<=k;j++){
			ll x=read(),y=read();
			v[x].push_back(a);
			build(x,1,x,v[x].size()-1,y);
			if(j!=1)build(x,v[x].size()-1,last,v[last].size()-1,0);
			last=x;
		}
	}	
	for(ll i=1;i<=qu;i++){
		ll op=read(),ed=read();
		que[i]={op,ed,i,0};
	}
	sort(que+1,que+1+qu,cmp);
	for(int i=1;i<=qu;i++){
		dj(que[i].op);
		que[i].ans=d[que[i].ed][0];
		while(que[i+1].op==que[i].op){
			que[i+1].ans=d[que[i+1].ed][0];
			i++;
		}
	}
	sort(que+1,que+1+qu,cmp1);
	for(ll i=1;i<=qu;i++){
		cout<<que[i].ans<<'\n';
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
*/
