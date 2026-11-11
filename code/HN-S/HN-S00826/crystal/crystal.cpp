#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int MAXN=5e5+10;
LL n,m,ans=0;
LL a[MAXN],sum[MAXN];

LL red()
{
	LL ret=0,opt=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')opt=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
	 	ret*=10;
	 	ret+=ch-'0';
	 	ch=getchar();
	}
	return ret*opt;
}

LL cost(LL l,LL r,LL val)
{
	return val*(r-l+1)-(sum[r]-sum[l-1]);
}

int Find(int ind)
{
	LL val=a[ind];
	int l=1,r=ind;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(cost(mid,ind,val)>m)l=mid+1;
		else r=mid;
	}
	return l;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	clock_t st=clock();
	n=red(),m=red();
	for(int i=1;i<=n;i++)a[i]=red();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]; 
	for(int i=1;i<=n;i++)
	{
		int ind=Find(i);
		ans=max(ans,(LL)i-ind+1);
	}
	cout<<ans<<'\n';
///	clock_t ed=clock();
//	cerr<<(double)(ed-st)/ CLOCKS_PER_SEC<<'\n';
	return 0;
}
//miao miao miao
//mao mao bu hui zheng huo miao
//dan shi mao mao xiang shang mi huo xing wei da shang miao
//er qie mao mao ke yi gao su ni mao mao de kao chang you ren nv zhuang kao shi miao (bu shi mao mao!mao mao zheng chang chuan nan zhuang kao de miao)
//yi kan jiu shi da lao miao
