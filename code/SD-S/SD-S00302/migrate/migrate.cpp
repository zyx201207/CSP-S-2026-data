//when you use deque or vector,
//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define int long long
#define mid (l+r>>1)
using namespace std;
const int N=2e6+1;
int _,T,n,m,ans,w[N],a[N],b[N],f[N],g[N];
int l[N],r[N],s[N],t[N];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
int calc(int ql,int qr,int x) {
	ql=max(ql,l[x]),qr=min(qr,r[x]);
	return ql<=qr?qr-ql+1:0;	
}
int Calc(int ql,int qr,int x) {
	ql=max(ql,s[x]),qr=min(qr,t[x]);
	return ql<=qr?qr-ql+1:0;
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	_=read(),T=read();
	while (T--) 
	{
		n=read(),m=read(),ans=0;
		for (int i=1;i<=n;i++) w[i]=read(),f[i]=g[i]=r[i]=t[i]=0,l[i]=s[i]=n+1;
		for (int i=1,j=1;i<=n;i++) {
			while (w[i]-w[j]>m) j++;
			a[i]=j;
			l[a[i] ]=min(l[a[i] ],i);
			r[a[i] ]=i;
		}
		for (int i=n,j=n;i;i--) {
			while (w[j]-w[i]>m) j--;
			b[i]=j;
			t[b[i] ]=max(t[b[i] ],i);
			s[b[i] ]=i;
		}
		for (int i=1;i<=n;i++) {
			if (b[i]>i&&a[b[i] ]<=i) f[b[i] ]++; 
			if (b[i]>i&&a[b[i] ]==i) f[b[i] ]+=f[i];
		}
		for (int i=n;i;i--) {
			if (a[i]<i&&b[a[i] ]>=i) g[a[i] ]++;
			if (a[i]<i&&b[a[i] ]==i) g[a[i] ]+=g[i];
		}
		for (int i=1;i<n;i++) {
			if (b[a[i] ]==i+1&&a[b[i+1] ]==i) ans+=f[a[i] ]*g[b[i+1] ];
			int cnt=calc(i+2,b[i+1],i),Cnt=Calc(a[i],i-1,i+1);
			if (b[a[i] ]==i+1) ans+=(f[a[i] ])*cnt;
			if (a[b[i+1] ]==i) ans+=(g[b[i+1] ])*Cnt;
			ans+=cnt*Cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
16:13 Í¨¹ý T3 
*/
