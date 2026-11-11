//16 18 2/5 0pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
vector<int> nbr[N];
int n,k,u[N],v[N],fa[N];
bool f[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
	return;
}
int maxd;
void dfs(int cur,int fa,int dis){
	if(dis>maxd){
		maxd=dis;
	}
	for(int nxt:nbr[cur]){
		if(nxt==fa||f[nxt]){
			continue;
		}
		dfs(nxt,cur,dis+1);
	}
	return;
}
int help(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		nbr[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		u[i]--;
		v[i]--;
		nbr[u[i]].push_back(v[i]);
		nbr[v[i]].push_back(u[i]);
	}
	int ans=n;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k){
			continue;
		}
//		cerr<<"!\n";
		for(int j=0;j<n;j++){
			fa[j]=j;
			if((i>>j)&1){
				f[j]=true;
//				cerr<<"@"<<j<<endl;
			}
			else{
				f[j]=false;
			}
		}
		for(int j=1;j<n;j++){
			if(f[u[j]]&&f[v[j]]){
//				cerr<<"!"<<j<<endl;
				add(u[j],v[j]);
			}
		}
		int r1=0,r2=0;
		int maxi=0;
		for(int j=0;j<n;j++){
			if(!f[j]){
				continue;
			}
			if(r1==0){
				r1=find(j);
			}
			else if(find(j)!=r1){
				if(!r2){
					r2=find(j);
				}
				else if(find(j)!=r2){
//					cerr<<"NOT OK\n";
					goto ed;
				}
			}
		}
		for(int j=0;j<n;j++){
			if(!f[j]){
				continue;
			}
			maxd=0;
			dfs(j,0,0);
			maxi=max(maxi,maxd);
		}
//		cerr<<"$"<<maxi<<endl;
		ans=min(ans,maxi);
		ed:;
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<help()<<endl;
	}
	return 0;
}
/*
CCF help me plz!
(I wrote the same words last year.)
--Luogu 740325

no! ... --18:26
*/
