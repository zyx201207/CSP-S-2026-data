#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c;
int read(){
	int f=1,a=0;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return f*a;
}
#define pii pair<int,int>
#define v first
#define d second
vector<vector<int>> g;
vector<int> len,ml,ms[2];
int rt,ctr1,ctr2;
void dfs(int v,int f){
	int sum=0;
	for(int i:g[v]){
		if(i==f) continue;
		dfs(i,v);
		sum+=len[i];
	}
	len[v]=sum+1;
}
void fc(int v,int f){
	int mx=0;
	for(int i:g[v]){
		if(i==f) continue;
		mx=max(mx,len[i]);
		fc(i,v);
	}
	ml[v]=max(mx,len[rt]-len[v]);
	if(ml[v]<ml[ctr1]) ctr1=v;
	else if(ml[v]==ml[ctr1]) ctr2=v;
}
int t;
void gs(int v,int f){
	int mx=0;
	for(int i:g[v]){
		if(i==f) continue;
		fc(i,v);
		mx=max(mx,ms[t][i]);
	}
	ms[t][v]=mx+1;
}
vector<bool> in;
struct cpb{
	int v,l;
	bool r;
	bool operator <(const cpb w)const{
		return l<w.l;
	}
	bool operator >(const cpb w)const{
		return l>w.l;
	}
};
void solve(){
	int n,k,ctr;
	n=read();k=read();
	g.resize(n+1);
	len.resize(n+1);
	ml.resize(n+1);
	ms[0].resize(n+1);
	ms[1].resize(n+1);
	in.resize(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ml[0]=INT_MAX;
	rt=1;
	dfs(rt,0);
	fc(1,0);
	rt=ctr;
	dfs(rt,0);
	t=0;
	gs(rt,0);
	t=1;
	int mn=INT_MAX,cnt=0;
	bool mode=0;
	priority_queue<cpb> q;
	q.push({ctr1,INT_MAX,0});
	q.push({ctr2,INT_MAX,1});
	in[ctr1]=in[ctr2]=1;
	while(cnt<k){
		cpb k=q.top();q.pop();
		cnt++;
		mn=min(mn,k.l);
		if(in[k.v]) mode=1;
		in[k.v]=1;
		for(int i:g[k.v]){
			if(in[i]) continue;
			if(!mode) q.push((cpb){i,ms[k.r][i],k.r});
			else q.push((cpb){i,min(ms[0][i],ms[1][i]),1});
		}
	}
	cout<<mn<<'\n';
}
int main(){
	int t;
	read();t=read();
	while(t--) solve();
}