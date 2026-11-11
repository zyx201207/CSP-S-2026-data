#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[N],ans=INT_MIN,f[N],val[N],idx;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a + 1, a + n + 1);
	a[0]=1e18;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]==a[i-1]) val[idx]++;
		else val[++idx]++,f[idx]=a[i];
	}
	for(int i=2;i<=idx;i++) val[i]+=val[i-1];
	for (int i=1;i<=idx;i++) {
		int now=0,flag=0;
		for (int j=2;i+j-1<=idx;j++)
			if(now+(val[i+j-2]-val[i-1])*(f[i+j-1]-f[i+j-2])<=m) {now+=(val[i+j-2]-val[i-1])*(f[i+j-1]-f[i+j-2]);}
			else {ans=max(ans,val[i+j-2]-val[i-1]);flag=1;break;}
		if(!flag) ans=max(ans,val[idx]-val[i-1]);
	}
	cout<<ans<<'\n';
	return 0;
}