#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int n,m;
vector<int> v[N];
namespace sub1{
	int ans,mxdep[N],dis[N];
	void dfs(int u,int fath){
		mxdep[u]=0,dis[u]=0;
		int maxn=0,maxn2=0;
		for(int j:v[u])if(j^fath){
			dfs(j,u);
			mxdep[u]=max(mxdep[u],mxdep[j]+1);
			if(mxdep[j]+1>maxn)maxn2=maxn,maxn=mxdep[j]+1;
			else if(mxdep[j]+1>maxn2)maxn2=mxdep[j]+1;
			dis[u]=max(dis[u],dis[j]);
		}
		dis[u]=max(dis[u],maxn+maxn2);
	}
	void dfs2(int u,int fath,int fdep,int fdis){
		int mxdis=fdis,mxdis2=0,mxdisi=0,mxd=fdep,mxd2=0,mxd3=0,mxdi=0,mxd2i=0;
		for(int j:v[u])if(j^fath){
			if(dis[j]>mxdis)mxdis2=mxdis,mxdis=dis[j],mxdisi=j;
			else if(dis[j]>mxdis2)mxdis2=dis[j];
			if(mxdep[j]+1>mxd)mxd3=mxd2,mxd2=mxd,mxd=mxdep[j]+1,mxd2i=mxdi,mxdi=j;
			else if(mxdep[j]+1>mxd2)mxd3=mxd2,mxd2=mxdep[j]+1,mxd2i=j;
			else if(mxdep[j]+1>mxd3)mxd3=mxdep[j]+1;
		}
		for(int j:v[u])if(j^fath){
			int tdis=max((mxdisi==j?mxdis2:mxdis),(mxdi==j?mxd2+mxd3:(mxd2i==j?mxd+mxd3:mxd+mxd2))),tdep=(mxdi==j?mxd2:mxd);
			ans=min(ans,max((dis[j]+1)/2,(tdis+1)/2));
			dfs2(j,u,tdep+1,tdis);
		}
	}
	void solve(){
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int aa,bb;scanf("%lld%lld",&aa,&bb);
			v[aa].push_back(bb),v[bb].push_back(aa);
		}ans=(int)(1e18);
		dfs(1,0),dfs2(1,0,0,0);
		printf("%lld\n",ans);
	}
}
namespace sub2{
	void solve(){
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int aa,bb;scanf("%lld%lld",&aa,&bb);
			v[aa].push_back(bb),v[bb].push_back(aa);
		}
		if(n==m)return puts("0"),void();
		n/=2;
		if(m>=n)return puts("1"),void();
		for(int i=2;i<=n;i++){
			int l=i,r=n-i+1;
			if(r-l+1<=m)return printf("%lld\n",i),void();
			int t=r-l+1-m;
			if((t+1)/2+1<=i)return printf("%lld\n",i),void();
		}
	}
}
namespace sub3{
	int qa[N],qb[N],fa[N],stt[N],st[N],dis[N],mxdep[N],siz[N];
	vector<int> pnt;
	void dfs(int u,int fath){
		pnt.push_back(u),fa[u]=fath;
		for(int j:v[u])if(j!=fath&&!st[j])dis[j]=dis[u]+1,dfs(j,u);
	}
	void dfs2(int u,int fath,int lim){
		mxdep[u]=stt[u]=siz[u]=0;
		for(int j:v[u])if(j!=fath&&!st[j])dfs2(j,u,lim),stt[u]|=stt[j],mxdep[u]=max(mxdep[u],mxdep[j]+1),siz[u]+=siz[j];
		stt[u]|=(mxdep[u]==lim);
		siz[u]+=stt[u];
	}
	bool check(int mid){
		for(int i=1;i<n;i++){
			st[qb[i]]=1;
			pnt.clear(),dis[qa[i]]=0,dfs(qa[i],0);
			int maxn=-1,maxi=0;
			for(int j:pnt)if(dis[j]>maxn)maxn=dis[j],maxi=j;
			pnt.clear(),dis[maxi]=0,dfs(maxi,0);
			maxn=-1,maxi=0;
			for(int j:pnt)if(dis[j]>maxn)maxn=dis[j],maxi=j;
			if((maxn+1)/2<=mid)siz[maxi]=1;
			else{
				for(int j=1;j<=maxn/2;j++)maxi=fa[maxi];
				dfs2(maxi,0,mid);
			}st[qb[i]]=0;
			int res=siz[maxi];
			st[qa[i]]=1;
			pnt.clear(),dis[qb[i]]=0,dfs(qb[i],0);
			maxn=-1,maxi=0;
			for(int j:pnt)if(dis[j]>maxn)maxn=dis[j],maxi=j;
			pnt.clear(),dis[maxi]=0,dfs(maxi,0);
			maxn=-1,maxi=0;
			for(int j:pnt)if(dis[j]>maxn)maxn=dis[j],maxi=j;
			if((maxn+1)/2<=mid)siz[maxi]=1;
			else{
				for(int j=1;j<=maxn/2;j++)maxi=fa[maxi];
				dfs2(maxi,0,mid);
			}st[qa[i]]=0;
			res+=siz[maxi];
			if(res<=m)return true;
		}
		return false;
	}
	void solve(){
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			scanf("%lld%lld",qa+i,qb+i);
			v[qa[i]].push_back(qb[i]),v[qb[i]].push_back(qa[i]);
		}
		if(n==m)return puts("0"),void();
		int l=1,r=n,ans=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tes,_;cin>>tes>>_;
	while(_--){
		scanf("%lld%lld",&n,&m);
		if(m==2){
			sub1::solve();
			continue;
		}
		if(n>4000){
			sub2::solve();
			continue;
		}
		sub3::solve();
	}
}
