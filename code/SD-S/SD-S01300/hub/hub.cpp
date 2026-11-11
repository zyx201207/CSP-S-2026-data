#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
#define rd read()
const int N=1e6+10;
vector<int>vc[N];
int sz[N];
bool is_son[N];
vector<int>son;
void dfs1(int u,int f){
	sz[u]=1;
	for(auto it:vc[u]){
		if(it==f) continue;
		dfs1(it,u);
		sz[u]+=sz[it];
	}
	if(sz[u]==1){
		son.emplace_back(u);
		is_son[u]=1;
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=rd,t=rd;
	while(t--){
		int n=rd,k=rd;
		for(int i=1;i<n;i++){
			int u=rd,v=rd;
			vc[u].emplace_back(v);
			vc[v].emplace_back(u);
		}
		if(c>=13&&c<=14) cout<<((n>>1)-k)/4+(((n>>1)-k)%4==0?0:1)+1<<'\n';
		
	}
	return 0;
}

