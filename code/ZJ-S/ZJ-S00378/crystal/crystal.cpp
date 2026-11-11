#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,m,a[maxn],sum[maxn],ans;
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
bool check(int L,int R){return a[R]*(R-L+1)-(sum[R]-sum[L-1])<=m;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int R=1;
	for(int i=1;i<=n;i++){
		while(R<n&&check(i,R+1)) R++;
		ans=max(ans,R-i+1);
	}
	write(ans),putchar('\n');
	return 0;
}
