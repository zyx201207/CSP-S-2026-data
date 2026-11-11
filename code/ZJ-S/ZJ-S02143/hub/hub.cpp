#include<bits/stdc++.h>
#define int long long
#define U(a,b,c) for(int a=b;a<=c;a++)
#define D(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=5e5+10,M=5e5+10;
vector<int> edge[N];
int depth[N],IDdepth[N],Mdepth[N],Ndepth[N],ff[N];
void dfs(int u,int fa){
	for(auto v:edge[u]){
		if(v==fa) continue;
		dfs(v,u);
		if(Mdepth[v]+1>Mdepth[u]) Ndepth[u]=Mdepth[u],Mdepth[u]=Mdepth[v]+1,IDdepth[u]=v;
		else if(Mdepth[v]+1>Ndepth[u]) Ndepth[u]=Mdepth[v]+1;
	}
	return ;
}
void dfs1(int u,int fa){
	if(u!=1){
		if(IDdepth[fa]!=u){
			if(Mdepth[fa]+1>Mdepth[u]) Ndepth[u]=Mdepth[u],Mdepth[u]=Mdepth[fa]+1,IDdepth[u]=fa;
			else if(Mdepth[fa]+1>Ndepth[u]) Ndepth[u]=Mdepth[fa]+1;
		}else{
			if(Ndepth[fa]+1>Mdepth[u]) Ndepth[u]=Mdepth[u],Mdepth[u]=Ndepth[fa]+1,IDdepth[u]=fa;
			else if(Ndepth[fa]+1>Ndepth[u]) Ndepth[u]=Ndepth[fa]+1;
		}
	}
	for(auto v:edge[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
	return ;
}
void dfs2(int u,int fa){
	ff[u]=fa;
	depth[u]=depth[fa]+1;
	for(auto v:edge[u]){
		if(v==fa) continue;
		dfs2(v,u);
	}
	return ;
}
int root,ress,sum[N],res1=0,res2=0,res3=0;
bool used[N],color[N];
int f[N];
int ttt;
vector<int> vec;
void dfs3(int u,int prev){
	if(!color[u]) return ;
	if(u==root&&f[u]<=2){
		res1++;
		res3=max(res3,min(res1,ttt));
	}
	else if(f[u]){
		prev=u;
		res2=0;
	}else{
		res2++;
		res3=max(res2,min(res2,ttt));
	}
	for(auto v:edge[u]){
		if(v==ff[u]) continue;
		dfs3(v,prev);
	}
	return ;
}
int check(int mid){
	ttt=mid;
	int ans=0;
	vector<int> sum;
	U(i,0,vec.size()-1){
		if(depth[vec[i]]<mid) continue;
		sum.push_back(vec[i]);
	}
	U(i,0,sum.size()-1){
		int res=mid,now=sum[i];
		if(used[now]) continue;
		used[now]=1;
		bool tt=0;
		while(res){
			if(used[now]||color[now]){
				tt=1;
				f[tt]=1;
				break;
			}
			used[now]=1;
			res--;
			now=ff[now];
		}
		if(tt) continue;
		f[now]+=5;
		while(now!=root){
			if(color[now]){
				f[now]++;
				break;
			}
			ans++;
			color[now]=1;
			now=ff[now];
		}
	}
	dfs3(root,0);
	return ans-ttt;
}
bool cmp(int x,int y){
	return depth[x]>depth[y];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		vec.clear();
		int n,k;
		cin>>n>>k;
		U(i,1,n-1){
			int u,v;
			cin>>u>>v;
			edge[u].emplace_back(v);
			edge[v].emplace_back(u);
		}
		dfs(1,0);
		dfs1(1,0);
		root=0;
		U(i,1,n) if(root==0||Mdepth[i]<Mdepth[root]) root=i;
		depth[0]=-1;
		dfs2(root,0);
		U(i,1,n){
			if(edge[i].size()==1) vec.emplace_back(i);
		}
		sort(vec.begin(),vec.end(),cmp);
		int l=0,r=Mdepth[root],anss=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)<=k){
				anss=mid;
				l=mid+1;
			}else r=mid-1;
		}
		cout<<anss<<"\n";
	}
	return 0;
}