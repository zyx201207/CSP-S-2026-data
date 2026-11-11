#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=1e6+10;
int C,T,n,k,fa[N],dep[N],dis[N],ans=1e9+10;
vector<int> g[N],v;
bool vis[N];
void dfs(int u,int f){
	fa[u]=f;dep[u]=dep[f]+1;
	for(int i:g[u]){
		if(i!=f){
			dfs(i,u);
		}
	}
}
void dfs1(int u){
//	cout<<v.size()<<"\n";
	if(v.size()>k) return;
	if(v.size()==k){
//		cout<<u;
		int mx=-1;
		queue<int> q;
		L(i,1,n) dis[i]=1e9;
		for(int i:v) q.push(i),dis[i]=0;
		while(q.size()){
			int t=q.front();
			q.pop();
			for(int i:g[t]){
				if(dis[i]>dis[t]+1){
					dis[i]=dis[t]+1;
					q.push(i);
				}
			}
		}
		L(i,1,n) mx=max(mx,dis[i]);
//		cout<<mx<<" ";
		ans=min(ans,mx);
		return;
	}
	int len=v.size();
	L(i,0,len-1){
		for(int j:g[v[i]]){
//			cout<<u<<" "<<i<<" "<<j<<" "<<len<<" "<<v.size()<<"\n";
			if(dep[j]<dep[u] && !vis[j]){
				v.push_back(j);
//				cout<<v.size()<<":\n";
				vis[j]=1;
				dfs1(u);
				vis[j]=0;
				v.erase(v.end()-1);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=1e9+10;
		cin>>n>>k;
		L(i,1,n) g[i].clear();
		L(i,2,n){
			int l,r;
			cin>>l>>r;
			g[l].push_back(r);
			g[r].push_back(l);
		}
		dfs(1,0);
		//yi:
		v.clear();
		L(i,1,n){
			v.push_back(i);
			L(k,1,n) vis[k]=0;
			vis[i]=1;
			dfs1(i);
			v.clear();
		}
		//er:
		v.clear();
		L(i,1,n){
			L(j,1,n){
				if(i!=j){
//					cout<<i<<" "<<j<<"%\n";
					v.clear();
					L(k,1,n) vis[k]=0;
					vis[i]=vis[j]=1;
					v.push_back(i);
					v.push_back(j);
					dfs1(i);
				}
			}
		}		
		cout<<ans<<"\n";
	}
	return 0;
}