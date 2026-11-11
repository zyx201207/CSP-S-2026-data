#include<bits/stdc++.h>
#define ll long long
const int N = 5e5+10;
using namespace std;
template<class T>
inline void read(T &sum){
	int c = sum = 0;bool y = 1;
	while(c!='-'&&(c<'0'||c>'9'))if(c==EOF)return;else c=getchar();
	if(c=='-')y=0,c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	sum=y?sum:-sum;
}
struct node{
	int to;
	ll l;
};
int n,t;
bool v[N];
ll m,a[N],z[N],ded=0,s;
vector<node> q[N];/*
inline bool sss(int x, int y,int s){
	if(x == s) return 1;
	for(auto i:q[x])
		if(!v[i.to] && i.to!=y) dfs(i.to,x);
	
}*/
inline void dfs(int x, int y){
	for(auto i:q[x])
		if(!v[i.to]) v[i.to] = 1,dfs(i.to,x);
	//dfs() 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(t);read(t);
	while(t--){
		read(n),read(m);
		cout << 0 << endl;
		memset(v,0,sizeof v);
		for(int i = 1; i <= n; i++) q[i].clear();
		for(int i = 1,j; i <= n; i++){
			read(a[i]);j=i-1;
			while(a[i]-a[j]<=m&&j>0){
				q[j].push_back({i,a[i]-a[j]});
				j--;
			}
		}
		//dfs(1,0);*/
	}
	return 0;
}
