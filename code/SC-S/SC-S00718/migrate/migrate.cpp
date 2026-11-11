#include<bits/stdc++.h>
/*
16:03 开题
16:08 会 40pts 
16:52 40pts
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
int c,T;
namespace small{
	int n,d,a[2000005],dp[2000005],pos,ans,du,num[2000005],cnt[2000005];
	bool fl;
	void solve(){
		ans=0,read(n,d);rep(i,1,n)read(a[i]);
		rep(i,1,n){pos=i,dp[i]=0,num[i]=1,cnt[0]=1,fl=0;
			rep(j,1,n)cnt[j]=0;
			rep(j,i+1,n){num[j]=0;
				while(a[j]-a[pos]>d)cnt[dp[pos]]-=num[pos],++pos;
				if(pos==j)break;
				dp[j]=dp[pos]+1,num[j]=cnt[dp[pos]],cnt[dp[j]]+=num[j];
				if(num[j]==2)++ans;
//				if(num[j]>2)break;
//				cout<<i<<" "<<j<<" "<<pos<<" "<<ans<<'\n'; 
			}
		}print(ans),putchar('\n');
	}
	void work(){
		read(T);rep(i,1,T)solve();
	}
}
signed main(){
	ztyroy_AK_CSPS2026
	hyc_qcz_jmr_baoyouwo_AC	
//	freopen("migrate5.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);
	if(c<=10){small::work();made_by_ztyroy}
	small::work();
	made_by_ztyroy
}
/*
fc/n /w D:\work\migrate3.ans D:\work\migrate.out
*/
/*
0 1
5 3
0 2 3 4 6
*/