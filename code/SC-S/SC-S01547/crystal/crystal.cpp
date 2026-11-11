#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10,mod=998244353,inf=1e18+10;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) k=k*10+c-'0',c=getchar();
	return k*f; 
}
int a[maxn],pre[maxn],n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i]; 
	int l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		int tmp=inf;
		for(int i=mid;i<=n;i++) tmp=min(tmp,a[i]*mid-(pre[i]-pre[i-mid]));
		if(tmp<=m) ans=mid,l=mid+1;
		else r=mid-1; 
	}
	cout<<ans<<'\n';
	return 0;
}
