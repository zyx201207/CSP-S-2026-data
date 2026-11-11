#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
namespace subtask_1{
	int f[15],dis[15][15],vis[15],n,k,u,v;
	vector<int> a[15];
	map<int,int> mp;
	int find(int x){
		if(f[x]!=x)f[x]=find(f[x]);
		return f[x];
	}
	void dfs1(int rt,int x,int fa){
		for(auto v:a[x]){
			if(v==fa)continue;
			dis[rt][v]=dis[rt][x]+1;
			dfs1(rt,v,x);
		}
	}
	void dfs(int x,int fa){
		for(auto v:a[x]){
			if(v==fa)continue;
			if(vis[v]&&vis[x]){
				int xx=find(v),yy=find(x);
				if(xx!=yy){
					f[xx]=yy;
				}
			}
			dfs(v,x);
		}
	}
	int check(){
		int all=0;
		mp.clear();
		for(int i=1;i<=n;i++)f[i]=i;
		dfs(1,1);
		for(int i=1;i<=n;i++){
			if(!vis[i])continue;
			if(!mp[f[i]]){
				mp[f[i]]=1;
				all++;
			}
		}
		if(all<=2)return 1;
		return 0;
	}
	void main(){
		while(T--){
			int Ans=LLONG_MAX;
			mp.clear();
			memset(dis,0,sizeof(dis));
			cin>>n>>k;
			for(int i=1;i<=n;i++)a[i].clear();
			for(int i=1;i<=n-1;i++){
				cin>>u>>v;
				a[u].push_back(v);
				a[v].push_back(u);
			}
			for(int i=1;i<=n;i++){
				dfs1(i,i,i);
			}
			for(int i=0;i<(1<<n);i++){
				int s=0,ans=0;
				for(int p=1;p<=n;p++)vis[p]=0;
				for(int p=1;p<=n;p++){
					if((1<<(p-1)&i))s++,vis[p]=1;
				}
				if(s==k){
					if(check()){
						//for(int i=1;i<=n;i++){
						//	cout<<vis[i];
						//}
						//cout<<"\n";
						int ans=0;
						for(int p=1;p<=n;p++){
							if(vis[p])continue;
							int sum=LLONG_MAX;
							for(int q=1;q<=n;q++){
								if(vis[q]){
									sum=min(sum,dis[p][q]);
								}
							}
							ans=max(ans,sum);
						}
						Ans=min(Ans,ans);
					}
				}
			}
			cout<<Ans<<"\n";
		}
	}
}
namespace subtask_2{
	int n,k,u,v;
	void main(){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n-1;i++){
				cin>>u>>v;
			}
			if(k==n){
				cout<<"0\n";continue;
			}
			if(k>=n/2){
				cout<<"1\n";continue;
			}
			cout<<((n/2+2-k+1)/2+1)/2<<"\n";
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c==13||c==14)subtask_2::main();
	else subtask_1::main();
	return 0;
}
