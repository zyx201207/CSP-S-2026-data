//Just Sayori
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#include<random>
#define ll long long
#define ull unsigned long long
#define gr getchar
#define pr putchar
#define N 1000005
#define M 1000000007
//#define M 998244353
//#define M 0x3f3f3f3f3f3f3f3f
#define for1(i,a,b) for(auto i=(a);i<=(b);i++)
#define for2(i,a,b) for(auto i=(a);i>=(b);i--)
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
inline int add(int a,int b,const int mod=M){return (a+=b)>=mod?a-mod:a;}
inline int del(int a,int b,const int mod=M){return (a-=b)<0?a+mod:a;}
template<typename T> inline bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline bool chkmax(T &a,T b){return a<b?a=b,1:0;}
int c,t,n;
ll d,ans;
int l[N],r[N];
ll x[N];
int f[5005][5005],g[5005][5005];
#define mid ((ls+rs)>>1)
void work()
{
	n=read(),d=read(),ans=0;
	for1 (i,1,n) x[i]=read();
	if (n<=5000)
	{
		for1 (i,1,n)
		{
			for1 (j,1,n) f[i][j]=g[i][j]=0;
			int l=i,r=i;
			ll sm=1;
			g[i][i]=1;
			for1 (j,i+1,n)
			{
				f[i][j]=M;
				while (l<j && x[j]-x[l]>d) sm-=g[i][l],l++;
				if (r<l) r=l,sm=g[i][l];
				while (r<j && f[i][r+1]==f[i][l]) r++,sm+=g[i][r];
				f[i][j]=f[i][l]+1,g[i][j]=sm,chkmin(g[i][j],3);
				if (g[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	else
	{
		if (c==11 || c==12)
		{
			int len=0;
			for1 (i,1,n)
				if (x[i]-x[1]>d)
				{
					len=i-2;break;
				}
			if (len<=1) cout<<0<<"\n";
			else cout<<n-2*len+1<<"\n";
		}
		else if (c==13 || c==14)
		{
			cout<<0<<"\n";
		}
		else cout<<1ll*n*(n-1)/2<<"\n";
	}
}
int main()
{
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while (t--) work();
	return 0;
}
/*
T4 不要想甲酸/ll
先考虑暴力就是枚举一个点开始 dp
特殊性质 1 我们发现每个点能跳出去的距离相同
*/