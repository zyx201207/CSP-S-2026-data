/*
by Cao_longjun
这应该是我最后一次进CSP-S的考场了，非常感谢OI，我接触到了电脑，接触到了一群友善的Oier，如今也是轮到我AFO了 
江畔何人初见月，江月何年初见人啊 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	for(int r=1,l=1;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m) sum-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
