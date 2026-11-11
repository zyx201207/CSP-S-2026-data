#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Memory_Love{
	int read(){ int x=0; char ch=getchar(); bool flag=1;
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag==1? 1:-1)*x;}
	void write(int x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
} using namespace Memory_Love;
const int N=5e5+5;
int n,m,a[N],sum[N];

/*
namespace Lisanhua
{
	int A[N],cnt;
	int Get(int x)
	{
		return lower_bound(A+1,A+1+cnt,x)-A;
	}
	int solve()
	{
		int i;
		for(i=1;i<=n;i++) A[++cnt]=a[i];
		sort(A+1,A+1+cnt);
		cnt=unique(A+1,A+1+cnt)-A-1;
		for(i=1;i<=n;i++) a[i]=Get(a[i]);
		return cnt;
	}
} using Lisanhua::A;
*/

int SUM(int L,int R)
{
	return sum[R]-sum[L-1];
}
int check(int L,int R,int x)
{
	int len=R-L+1;
	return len*x-SUM(L,R);
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,Answer=1; n=read(),m=read();
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	int V=Lisanhua::solve();
	int Pos=1;
	for(i=1;i<=n;i++)
	{
		while(Pos<=i && check(Pos,i,a[i])>m) Pos++;
		Answer=max(Answer,i-Pos+1);
	}
	write(Answer,'\n');
	return 0;
}
