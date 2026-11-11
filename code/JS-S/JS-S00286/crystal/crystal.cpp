#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,a[500005],d[500005];
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int l=i,r=i+x-1;
		//l~mid mid+1~r
		int tmp=a[r]*(r-l+1)-(d[r]-d[l-1]);
		if(tmp<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=a[i]+d[i-1];
	int l=1,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
//ni de yan mou zhuang man le shi jian
//ni de shen hou yong gu shi cheng pian
//ci sheng ruo meng,wo yuan xi shu liu nian
//yu ni gong xie,cang hai sang tian
