#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define il inline
#define re register
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=5e5+6;
int n,m,a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(re int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	re int now=1,awa=1,qwq=0;
	for(re int i=2;i<=n;i++){
		qwq+=(i-now)*(a[i]-a[i-1]);
		while(qwq>m)
			qwq-=(a[i]-a[now]),now++;
		awa=max(awa,i-now+1);
	}
	printf("%lld\n",awa);
	return 0;
}