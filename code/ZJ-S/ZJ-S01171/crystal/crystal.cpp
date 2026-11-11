#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
inline int read(){
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
inline void chkmax(int &a,int b){a=max(a,b);}
inline void chkmin(int &a,int b){a=min(a,b);}
const int N=5e5+5;
int n,m,a[N],b[N],ans;
inline bool check(int l,int r,int p){
	int x=p*(r-l+1)-(b[r]-b[l-1]);
	return x<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i-mid+1,i,a[i]))l=mid+1,res=mid;
			else r=mid-1;
		}
		chkmax(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}

