#include<bits/stdc++.h>
/*
15:05 开题
15:42 会 100pts
16:00 100pts
*/
#define ztyroy_AK_CSPS2026
#define hyc_qcz_jmr_baoyouwo_AC

#define int long long
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
namespace big{
	struct ori_node{
		int w;
		vector<pair<int,int> >to;
	}pp[500005];
	struct new_node{
		vector<pair<int,int> >inc;
		int k,dis[505];
	}p[505];
	int n,m,d,q,x,y,ans;
	constexpr int inf=0x3f3f3f3f3f3f3f3f;
	void solve(){
		read(n,m,d,q);rep(i,1,m)read(pp[i].w);
		rep(i,1,n){read(p[i].k);
			rep(j,1,n)p[i].dis[j]=inf*(i!=j);
			rep(j,1,p[i].k){read(x,y);
				p[i].inc.emplace_back(x,y);
				pp[x].to.emplace_back(i,y);
			}
		}
		rep(i,1,m)for(auto j:pp[i].to)for(auto k:pp[i].to)if(j.first!=k.first){
			p[j.first].dis[k.first]=p[k.first].dis[j.first]=
			min(p[j.first].dis[k.first],j.second+k.second);
		}
		rep(k,1,n)rep(i,1,n)if(i!=k)rep(j,1,n)if(j!=k&&i!=j){
			p[i].dis[j]=p[j].dis[i]=min(p[i].dis[j],p[i].dis[k]+p[k].dis[j]);
		}
		rep(i,1,q){read(x,y),ans=inf;
			for(auto j:pp[x].to)for(auto k:pp[y].to){
				ans=min(ans,p[j.first].dis[k.first]+j.second+k.second+pp[x].w+pp[y].w);
			}
			print(ans),putchar('\n');
		}
	}
}
signed main(){
	ztyroy_AK_CSPS2026
	hyc_qcz_jmr_baoyouwo_AC	
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);
	big::solve();
	made_by_ztyroy
}
/*
fc/n /w D:\work\subway7.ans D:\work\subway.out
*/