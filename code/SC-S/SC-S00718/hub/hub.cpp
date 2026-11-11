#include<bits/stdc++.h>
/*
16:53 开题
17:15 会 35pts 
17:33 k=2 做法假了，现在开打 30pts 
18:17 [30pts,50pts)
*/
#define ztyroy_AK_CSPS2026
#define hyc_qcz_jmr_baoyouwo_AC

#define int unsigned long long
#define made_by_ztyroy return 0;

#define rep(i,s,e) for(int i=s;i<=e;++i)
#define fep(i,s,e) for(int i=s;i<e;++i)
#define per(i,s,e) for(int i=s;i>=e;--i)
#define pef(i,s,e) for(int i=s;i>e;--i)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T c=getchar();T f=1;
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
		x*=f;
	}
	template <typename T,typename ...Args> inline void read(T &x,Args &...args){
		read(x),read(args...);
	}
	template <typename T> inline void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
	template <typename T,typename ...Args> inline void print(T x,Args ...args){
		print(x),putchar(' '),print(args...);
	}
}

using namespace std;
using namespace FastIO;
int c; 
namespace small{
	struct node{
		vector<int>son;
		int dep,fa,dis,siz;
		bool in;
	}p[1000005]; 
	int T,n,kk,u,v,ans,thi,num;
	constexpr int inf=0x3f3f3f3f3f3f3f3f;
	priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > >pq;
	inline ptm(int now,int fa,int dep){
		p[now].fa=fa,p[now].dep=dep,p[now].siz=1;
		for(auto i:p[now].son)if(i!=fa){
			ptm(i,now,dep+1),p[now].siz+=p[i].siz;
		}
	}
	inline find_sub(int now,int fa,int du){
		p[now].dis=1,p[now].in=1;for(auto i:p[now].son)if(i!=fa){
			find_sub(i,now,du);
			if(i!=du)p[now].dis=max(p[now].dis,p[i].dis+1);
			else p[now].dis=max(p[now].dis,1ull);
		}
	}
	inline dfs(int now,int dis,int fa){
		p[now].dis=min(p[now].dis,dis);
		for(auto i:p[now].son)if(i!=fa&&!p[i].in){
			dfs(i,dis+1,now);
		}
	}
	inline void solve(){
		ans=inf,read(n,kk);rep(i,1,n)vector<int>().swap(p[i].son);
		fep(i,1,n){read(u,v);
			p[u].son.emplace_back(v),
			p[v].son.emplace_back(u);
		}ptm(1,0,1);
		rep(i,1,n)rep(j,i+1,n){
			if(p[i].siz+p[j].siz<kk)continue;
			rep(k,1,n)p[k].dis=inf,p[k].in=0;
			find_sub(i,p[i].fa,j),find_sub(j,p[j].fa,i),
			dfs(i,0,0),dfs(j,0,0),thi=num=0;
			rep(k,1,n){
				if(!p[k].in)thi=max(thi,p[k].dis);
				else ++num;
			}
			if(num<kk)continue;
			priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > >().swap(pq);
			for(auto k:p[i].son)if(k!=p[i].fa&&j!=k)pq.push({p[k].dis,k});
			for(auto k:p[j].son)if(j!=p[j].fa&&i!=k)pq.push({p[k].dis,k});
			rep(k,1,kk-2){
				int now=pq.top().second;pq.pop();
				if(!p[now].in)continue;p[now].in=0;
				for(auto qw:p[now].son)if(qw!=p[now].fa)pq.push({p[qw].dis,qw});
			}
			while(!pq.empty()){
//				if(i==1&&j==3)cout<<i<<" "<<j<<" "<<pq.top().second<<" "<<pq.top().first<<'\n';
				thi=max(thi,pq.top().first),pq.pop();
			}
//			cout<<i<<" "<<j<<" "<<thi<<'\n';
			ans=min(ans,thi);
		}print(ans),putchar('\n');
	}
	inline void work(){
		read(T);rep(i,1,T)solve();
	}
}
signed main(){
	ztyroy_AK_CSPS2026
	hyc_qcz_jmr_baoyouwo_AC	
//	freopen("hub3.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);
	if(c<=10){small::work();made_by_ztyroy}
	small::work();
	made_by_ztyroy
}
