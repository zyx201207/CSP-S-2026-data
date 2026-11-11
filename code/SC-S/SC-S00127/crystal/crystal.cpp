#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=114514;
int n,m,maxn=-N;
int a[5*N],b[5*N],c[5*N];
map <int,int> tong;
void dfs(int x)
{
	if(x==0) return;
	for(int i=1;i<=n;i++)
	{
		a[i]++,tong[a[i]]++,maxn=max(maxn,tong[a[i]]),tong[a[i]-1]--;
		dfs(x-1);
		a[i]--,tong[a[i]]++,tong[a[i]+1]--;
	}
}
//void ddfs(int x)
//{
//	if(x<=0) return;
//	for(int i=1;i<=n;i++)
//	{
//		if(x>=(c[n]-c[i-1])/2)
//		a[i]+=(c[n]-c[i-1])/2,tong[a[i]]++,maxn=max(maxn,tong[a[i]]),tong[a[i]-(c[n]-c[i-1])/2]--;
//		dfs(x-(c[n]-c[i-1])/2);
//		a[i]-=(c[n]-c[i-1])/2,tong[a[i]]++,tong[a[i]+1]--;
//	}
//}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		tong[a[i]]++;
	}
	sort(a+1,a+n+1);
	bool checkab=true;
	for(int i=1;i<=n;i++) 
	{
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+a[i];
		if(b[i]!=b[i-1] && i-1>1) checkab=false;
	}
	if(checkab)//特殊A,B 13-18
	{
		double s=b[n],q=sqrt(s*s+8*s*m);
		cout<<q-s<<' '<<q<<' ';
		double maxn=(q-s)/(2*s);
		printf("%lld",((int)maxn+1<=n)?(int)maxn+1:n);
		exit(0);
	}
	if(m<=1000 || n<=16)
	{
		dfs(m);
		printf("%lld",maxn);
		exit(0);
	}
	else{
		int xixifu=n/2,l=xixifu,r=xixifu;
		for(int i=1;i<=xixifu;i++)
		{
			if(c[r+i]-c[l-i-1]>=m && c[r+i-1]-c[l-i+1]<m)
			{
				cout<<i*2;
				exit(0);
			}
		}
		printf("%lld",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}