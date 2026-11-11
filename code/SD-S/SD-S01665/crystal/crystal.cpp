#include<algorithm>
#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
bool Test_MLE_Start;
constexpr int N=5*1e5+10;
int _=1,n,m,ans=0,a[N],sum[N];
bool Test_MLE_End;
inline int reads(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}inline void clr(){
//	Don't Forget!

}inline void files(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}int finds(int r){
	int L=1,res=0,R=r;
	while(L<=R){
		int mid=(L+R)>>1,now;
		now=a[r]*(r-mid+1)-(sum[r]-sum[mid-1]);
		if(now<=m) res=mid,R=mid-1;
		else L=mid+1;
	}return r-res+1;
}
signed main(){
//	printf("%lf\n",(&Test_MLE_End-&Test_MLE_Start+1)/1024.0/1024.0);
	files();
//	_=reads();
	while(_--){
		clr();n=reads(),m=reads();
		for(int i=1;i<=n;i++) a[i]=reads();
		sort(a+1,a+n+1);for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for(int i=n;i>=1;i--) ans=max(ans,finds(i));
		printf("%lld\n",ans);
	}return 0;
}
/*
14:50 GG fk EZ
I can't get 1=
Does the author play crystal pvp or play minecraft pvp server?
I need to prepare the mid-term exam
Whk is more easy than OI!
*/
