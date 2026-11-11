#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace my{
	inline int read(){
		int c=getchar(),f=1,s=0;
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			s=s*10+(c^48);
			c=getchar();
		}
		return f*s;
	}
	int n,m,a[500005],c[500005],s[500005];
	int getsum(int l,int r){
		return a[r]*(r-l)-(s[r-1]-s[l]+a[l]);
	}
	bool check(int x){
		for(int i=1;i+x-1<=n;i++){
			if(getsum(i,i+x-1)<=m) return true;
		}
		return false;
	}
	signed main(){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		bool flagtoend=true;
		for(int i=1;i<=n;i++){
			c[i]=a[i]-a[i-1];
			s[i]=s[i-1]+a[i];
			if(c[i]<=m&&i!=1) flagtoend=false;
		}
		if(flagtoend){
			printf("1");
			return 0;
		}
		int L=1,R=n,Mid=0,ans=0;
		while(L<=R){
			Mid=((L+R)>>1);
			if(check(Mid)){
				L=Mid+1;
				ans=max(ans,Mid);
			}
			else{
				R=Mid-1;
			}
		}
		printf("%lld",ans);
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return my::main();
}
/*
1445 think a wrong way
1500 think a right way(maybe)
1510 test1&test2 accept
1512 test3 wrong
1523 find why alltest accept
test4 time 0.0874s
*/
