#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace solve{
	int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		return f*x;
	}
	const int N=1000005;
	int ans,n,d,a[N],dis[N],cnt[N];
	vector<int>edge[N];
	void bfs(int u){
		queue<pair<int,int>>q;
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		q.push({u,0});
		while(!q.empty()){
			int now=q.front().first;
			int w=q.front().second;
			q.pop();
			if(dis[now]<w)continue;
			if(dis[now]==w)cnt[now]++;
			if(dis[now]>w)dis[now]=w,cnt[now]=1;
			for(auto i:edge[now])
				q.push({i,w+1});
		}
	}
	void main(){
		n=read();d=read();ans=0;
		for(int i=1;i<=n;i++)
			edge[i].resize(0);
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]<=d){
					edge[i].emplace_back(j);
					edge[j].emplace_back(i);
				}
				else break;
			}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++)
				if(cnt[j]==2)ans++;
		}
		cout<<ans/2<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=solve::read(),T=solve::read();
	while(T--)solve::main();
	return 0;
}
