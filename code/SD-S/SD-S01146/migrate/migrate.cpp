#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
template<typename T>void read(T& x){
	T res=0,f=1;
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
const int MAXN=2e6+5;
ll n,d;
ll a[MAXN];
namespace _n2logn{
	ll _d[MAXN],cnt[MAXN];
	bool vis[MAXN];
	#define _  pair<int,int>
	vector<int> G[MAXN];
	void dijkstra(int s){
		for(int i=1;i<=n;i++){
			_d[i]=MAXN;
			cnt[i]=1;
			vis[i]=0;
		}
		priority_queue<_,vector<_>,greater<_>> q;
		_d[s]=0;
		q.push({_d[s],s});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u]){
				continue;
			}
			vis[u]=1;
			for(int v:G[u]){
				if(_d[u]+1<_d[v]){
					_d[v]=_d[u]+1;
					cnt[v]=cnt[u];
					q.push({_d[v],v});
				}
				else if(_d[u]+1==_d[v]){
					cnt[v]+=cnt[u];
				}
			}
		}
	}
	void _solve(){
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll dis=a[j]-a[i];
				if(dis<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		write(ans);
		el;
	}
}
namespace A{
	ll cnt[MAXN];
	void _solve(){
		ll num=d/(a[2]-a[1]);
		if(a[2]-a[1]>=d||(a[2]-a[1])*n<d){
			write(0);
			el;
			return;
		}
		write(n-(2*num-1));
		el;
	}
}
int c;
void solve(){
	read(n,d);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	if(c<=10&&n<=5000){
		_n2logn::_solve();
	}
	else{
		A::_solve();
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	read(c,T);
	while(T--){
		solve();
	}
	return 0;
}
/*
17:05 2h35min: 密码的多测没清空,暴力调出来了 
18:20 3h50min: 蒙对了特殊性质A 
*/
