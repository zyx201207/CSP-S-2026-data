#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
#define _for(i,u,v) for(int i=(u);i<=(v);i++)
#define for_(i,u,v) for(int i=(u);i>=(v);i--)
int n,k;
void solve1(){
	scanf("%d%d",&n,&k);
	int u,v;
	_for(i,1,n-1){
		scanf("%d%d",&u,&v);
	} if(n==k) { printf("0\n"); return; }
	n/=2,n++;
	if(k>=n) { printf("1\n"); return; }
	if(k==2){ printf("%d\n",(n+1)/4+1); return;	}
	int s=n-k;
	s=s/4+bool(s%4);
	printf("%d\n",s+1);
}
vector<int> q[N];
int dep[N]; bool ret[N];
int maxn,maxi;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(dep[x]>maxn) maxn=dep[x],maxi=x;
	for(auto y:q[x]){
		if(y==fa) continue;
		dfs(y,x);
	} 
}
void build(int x,int fa){
	for(auto y:q[x]){
		if(y==fa) continue;
		build(y,x);
		if(ret[y]) ret[x]=1;
	} 
}
int l,r; bool _nti[N];
int bre(int sss){
	maxn=0;
	dfs(sss,0);
	maxn=0; int ano=maxi;
	dfs(maxi,0); ret[maxi]=1;
	build(ano,0); 
	_for(i,1,n){
		if(ret[i]&&dep[i]==maxn/2) l=i;
		if(ret[i]&&dep[i]==maxn/2+1) r=i;
	} _for(i,0,q[l].size()-1){
		if(q[l][i]==r){ q[l].erase(q[l].begin()+i-1,q[l].begin()+i); break; }
	} _for(i,0,q[r].size()-1){
		if(q[r][i]==l){ q[r].erase(q[r].begin()+i-1,q[r].begin()+i); break; }
	}return maxn;
}
int bre2(int sss){
	maxn=0;
	dfs(sss,0);
	maxn=0; int ano=maxi;
	dfs(maxi,0); ret[maxi]=1;
	build(ano,0); 
	_for(i,1,n){
		if(ret[i]&&dep[i]==maxn/2) l=i;
		if(ret[i]&&dep[i]==maxn/2+1) r=i;
	} for(auto xy:q[r]) _nti[xy]=1;
	 q[r].erase(q[r].begin(),q[r].end());
	return maxn;
}
priority_queue<pair<int,int>> _cra;
bool www[N];
void solvet(){
	scanf("%d%d",&n,&k);
	int u,v;
	_for(i,1,n) q[i].clear();
	memset(www,0,sizeof(www)); memset(ret,0,sizeof(ret));
	_for(i,1,n-1){
		scanf("%d%d",&u,&v);
		q[u].push_back(v); q[v].push_back(u);
	} bre(1);
	int nl=l,nr=r;
	int fin1=bre2(nl);int _l=l,_r=r; int fin2=bre2(nr);
	fin1=(fin1)>>1;
	fin2=(fin2)>>1; 
	k-=2;
	_for(i,1,n){
		if(_nti[i]){
			maxn=0; dfs(i,0);
			_cra.push({maxn,i});
		}
	} while(k>0){
		auto xyz=_cra.top().second; www[xyz]=1;
		for(auto abc:q[xyz]){
			if(!www[abc]) _cra.push({_cra.top().first-1,abc});
		} _cra.pop();
	}printf("%d\n",_cra.top().first);
	while(!_cra.empty()) _cra.pop();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; scanf("%d%d",&c,&t);
	if(c==13||c==14){ while(t--) solve1();	}
	while(t--) solvet(); 
}

