#include<bits/stdc++.h>
/*
14:40 开题
14:42 会了 
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
int n,m,a[500005],l=1,sum,ans; 
signed main(){
	ztyroy_AK_CSPS2026
	hyc_qcz_jmr_baoyouwo_AC	
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n,m);rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1,less<int>());
	rep(r,1,n){sum+=(r-l)*(a[r]-a[r-1]);
//		cout<<l<<" "<<r<<" "<<sum<<'\n';
		while(sum>m)sum-=(a[r]-a[l]),++l;
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<" "<<sum<<" "<<ans<<" "<<a[r]<<'\n';
	}print(ans);
	made_by_ztyroy
}
