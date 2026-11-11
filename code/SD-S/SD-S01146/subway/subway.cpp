#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
template<typename T>void read(T& x){
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c)){
		res*=10;
		res+=c-'0';
		c=getchar();
	}
	x=res*f;
}
void read(){

}
template<typename T1,typename... Ts>void read(T1& x,Ts&... xs){
	read(x);
	read(xs...);
}
template<typename T>void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
void write(){

}
template<typename T1,typename... Ts>void write(T1 x,Ts...xs){
	write(x);
	putchar(' ');
	write(xs...);
}
#define el putchar('\n')
#define sp putchar(' ')
#define ll long long
const int MAXN=505;
const int MAXM=5e5+5;
int c,n,m,d,q;
int w[MAXM];
#define _ pair<ll,ll>
struct lines{
	int k,t;
	vector<_> g;//<a_i,t_i>
};
lines a[MAXN];
vector<_> Line[MAXM];//<line,idx>
bool is_connected(int u,int v){
	for(int i=0;i<Line[u].size();i++){
		for(int j=0;j<Line[v].size();j++){
			if(Line[i].first==Line[j].first){
				return 1;
			}
		}
	}
	return 0;
}
ll d[MAXM];
bool vis[MAXM];
void solve(int u,int v){
	for(int i=1;i<=m;i++){
		d[i]=2e18;
		vis[i]=0;
	}
	d[u]=0;
	ll ans=w[u]*1ll+w[v]*1ll;
	write(ans);
	el;
//	if(is_connected(u,v)){
//		write(ans);
//		el;
//		return;
//	}
//	priority_queue<_,vector<_>,greater<_>> q;//<dist,idx>
//	q.push({d[u],u});
//	while(!q.empty()){
//		int t=q.top().second;
//		q.pop();
//		if(vis[t]){
//			continue;
//		}
//		vis[t]=1;
//		for(_ it:Line[t]){
//			
//		}
//	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c,n,m,d,q);
	for(int i=1;i<=m;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		read(a[i].k);
		for(int j=0;j<a[i].k;j++){
			_ x;
			read(x.first,x.second);
			a[i].g.push_back(x);
			Line[x.first].push_back({i,j});
		}
	}
	while(q--){
		int u,v;
		read(u,v);
		solve(u,v);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
16:22 1h52min: T2打不出暴力,换题 
*/
