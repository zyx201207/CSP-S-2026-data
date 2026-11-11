#include<bits/stdc++.h>
using namespace std;
int ID,T,n,K;
vector<int>c[1000001];
namespace sub1{
	int ck(){
		return ID>=1&&ID<=3;
	}
	int b[11],dis[11];
	void dfs0(int i){
		if(!b[i])return;
		b[i]=0;
		for(int j:c[i]){
			if(b[j])dfs0(j);
		}
	}
	void main(){
		for(;T;T--){
			cin>>n>>K;
			for(int i=1;i<=n;i++)c[i].clear();
			for(int i=2,u,v;i<=n;i++)cin>>u>>v,c[u].push_back(v),c[v].push_back(u);
			int ans=114514;
			for(int x=0;x<(1<<n);x++){
				if(__builtin_popcount(x)!=K)continue;
				for(int i=1;i<=n;i++)b[i]=(x>>(i-1))&1;
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(b[i]){
						cnt++;
						dfs0(i);
					}
				}
				if(cnt>2)continue;
				for(int i=1;i<=n;i++)dis[i]=114514;
				queue<int>q;
				for(int i=1;i<=n;i++)if((x>>(i-1))&1)dis[i]=0,q.push(i);
				while(!q.empty()){
					const int i=q.front();q.pop();
					for(int j:c[i]){
						if(dis[j]>dis[i]+1){
							dis[j]=dis[i]+1;
							q.push(j);
						}
					}
				}
				int mx=0;
				for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
				ans=min(ans,mx);
			}
			cout<<ans<<'\n';
		}
	}
}
namespace subk{
	int ck(){
		return ID==7||ID==11||ID==12;
	}
	int dep[1000001],p[1000001],fa[1000001];
	void dfs0(int i,int FA){
		dep[i]=dep[FA]+1;
		fa[i]=FA;
		for(int j:c[i]){
			if(j!=FA){
				dfs0(j,i);
			}
		}
	}
	int dis[1000001];
	int CK(int D){
		const int A=p[1+D],B=p[p[0]-D];
		for(int i=1;i<=n;i++)dis[i]=1145141919;
		queue<int>q;
		dis[A]=0,q.push(A);
		dis[B]=0,q.push(B);
		while(!q.empty()){
			const int i=q.front();q.pop();
			for(int j:c[i]){
				if(dis[j]>dis[i]+1){
					dis[j]=dis[i]+1;
					q.push(j);
				}
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
		return mx<=D;
	}
	void main(){
		for(;T;T--){
			cin>>n>>K;
			for(int i=1;i<=n;i++)c[i].clear();
			for(int i=2,u,v;i<=n;i++)cin>>u>>v,c[u].push_back(v),c[v].push_back(u);
			int rt=1;
			dfs0(rt,0);
			for(int i=1;i<=n;i++)if(dep[i]>dep[rt])rt=i;
			dfs0(rt,0);
			int _rt=1;
			for(int i=1;i<=n;i++)if(dep[i]>dep[_rt])_rt=i;
			p[0]=0;
			for(int i=_rt;i;i=fa[i])p[++p[0]]=i;
			int l=0,r=(p[0]-1)/2,mi;
			while(l<=r){
				mi=(l+r)>>1;
				if(CK(mi))r=mi-1;
				else l=mi+1;
			}
			cout<<l<<'\n';
		}
	}
}
namespace subA{
	int ck(){
		return ID>=13&&ID<=14;
	}
	int dep[1000001],p[1000001],fa[1000001];
	void dfs0(int i,int FA){
		dep[i]=dep[FA]+1;
		fa[i]=FA;
		for(int j:c[i]){
			if(j!=FA){
				dfs0(j,i);
			}
		}
	}
	int dis[1000001];
	int CK(int D){
		const int B=p[p[0]-D];
		queue<int>q;
		for(int i=1;i<=n;i++)dis[i]=1145141919;
		for(int i=D+1;i<=D+K-1&&i<=p[0];i++)dis[p[i]]=0,q.push(p[i]);
		dis[B]=0,q.push(B);
		while(!q.empty()){
			const int i=q.front();q.pop();
			for(int j:c[i]){
				if(dis[j]>dis[i]+1){
					dis[j]=dis[i]+1;
					q.push(j);
				}
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
		return mx<=D;
	}
	void main(){
		for(;T;T--){
			cin>>n>>K;
			for(int i=1;i<=n;i++)c[i].clear();
			for(int i=2,u,v;i<=n;i++)cin>>u>>v,c[u].push_back(v),c[v].push_back(u);
			int rt=1;
			dfs0(rt,0);
			for(int i=1;i<=n;i++)if(dep[i]>dep[rt])rt=i;
			dfs0(rt,0);
			int _rt=1;
			for(int i=1;i<=n;i++)if(dep[i]>dep[_rt])_rt=i;
			p[0]=0;
			for(int i=_rt;i;i=fa[i])p[++p[0]]=i;
			if(K==n){
				cout<<0<<'\n';
				continue;
			}
			int l=1,r=(p[0]-1)/2,mi;
			while(l<=r){
				mi=(l+r)>>1;
				if(CK(mi))r=mi-1;
				else l=mi+1;
			}
			cout<<l<<'\n';
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ID>>T;
	if(sub1::ck()){
		sub1::main();
		return 0;
	}
	if(subk::ck()){
		subk::main();
		return 0;
	}
	if(subA::ck()){
		subA::main();
		return 0;
	}
	return 0;
}

