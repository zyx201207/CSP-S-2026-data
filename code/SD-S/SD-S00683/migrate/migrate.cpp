#include <bits/stdc++.h>
using namespace std;
#define drintf(...) //fprintf(stderr,__VA_ARGS__),fflush(stderr)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
ll rd(){
	ll x=0;
	bool flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return flag?x:-x;
}
const int maxn=2e6+10;
int c,T;
int n;
ll d;
ll x[maxn];
int rt[maxn];
namespace S40{
	int f[maxn];
	ll solve(int l,int r){
		ll tans=0ll;
		for(int i=l;i<=r;++i){
			f[i]=1;
			ll ans=0ll;
			int j1=i,j2=i;
			while(j2!=r){
				int y3=rt[j2];
				if(j1==j2){
					f[y3]=f[j2];
					if(y3>j2+1){
						f[y3-1]=f[j2];
					}
					if(f[j2]==2)ans+=y3-j2;
				}
				else{
					int y2=rt[j2-1];
					if(y2==y3){
						if(j1+1<j2){
							int y1=rt[j2-2];
							if(y1==y2)f[y3]=3;
							else f[y3]=f[j2-1]+f[j2];
						}
						else f[y3]=f[j2-1]+f[j2];
						if(f[y3]>3)f[y3]=3;
					}
					else{
						f[y3]=f[j2];
					}
					if(y3>j2+1){
						if(y3-1>y2){
							f[y3-1]=f[j2];
						}
						else{
							if(j1+1<j2){
								int y1=rt[j2-2];
								if(y1==y2)f[y3-1]=3;
								else f[y3-1]=f[j2]+f[j2-1];
							}
							else f[y3-1]=f[j2]+f[j2-1];
							if(f[y3-1]>3)f[y3-1]=3;
						}
					}
					if(j1+1<j2){
						int y1=rt[j2-2];
						if(f[j2]==2)ans+=y3-y2;
						else{
							if(f[j2]+f[j2-1]==2){
								ans+=y2-y1;
							}
						}
					}
					else{
						if(f[j2]==2)ans+=y3-y2;
						else if(f[j2]+f[j2-1]==2){
							ans+=y2-j2;
						}
					}
				}
				j1=j2+1;
				j2=y3;
			}
			tans+=ans;
		}
		
		return tans;
	}
}
ll solve(int l,int r){
//	if((1<=c&&c<=10)||(13<=c&&c<=18)){
		return S40::solve(l,r);
//	}
//	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();
	T=rd();
	while(T--){
		n=rd();
		d=rd();
		for(int i=1;i<=n;++i)x[i]=rd();
		for(int i=1;i<=n;++i){
			rt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			drintf("%d->%d\n",i,rt[i]);
		}
		int j=1;
		ll ans=0ll;
		for(int i=2;i<=n;++i){
			if(x[i]-x[i-1]>d){
				ans+=solve(j,i-1);
				j=i;
			}
		}
		ans+=solve(j,n);
		printf("%lld\n",ans);
	}
	return 0;
}

/*
1 1
8 4
0 1 2 3 4 5 9 11
*/
