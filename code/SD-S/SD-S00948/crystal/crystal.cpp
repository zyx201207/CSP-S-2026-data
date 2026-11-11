#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=5e5+10;
int n,cnt;
struct Node
{
	int len;
	LL s;
}d[N];
LL m,a[N],cha[N],sum[N];
bool cmp(Node a,Node b)
{
	return a.len>b.len;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	cha[1]=a[2]-a[1];
	int f=1;
	for(int i=2;i<n;i++)
	{
		cha[i]=a[i+1]-a[i];
		if(cha[i]!=cha[i-1]) f=0;
	}
	if(f==1)
	{
		LL t=cha[1];
		for(int i=1;i<=n;i++)
		{
			if((long long)t*i*(i+1)/2>m)
			{
				printf("%d",i);
				break;
			}
			  
		}
	}
	else
	{
	    for(int i=1;i<n;i++)
	    	sum[i]=cha[i]+sum[i-1];
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=n-i+1;j++)
	      	{
	      		LL tot=0;
	      	 	for(int k=i+j-1;k>0;k--)
	      	 	tot+=a[k]-a[i];
			 	if(tot>=m)
			 	{
			 		d[++cnt].len=i+j-2;
			 		d[cnt].s=tot;
			 		break;
			 	}
		  	}
		}
		sort(d+1,d+1+cnt,cmp);
	    printf("%d",d[1].len);  
	}
	return 0;
}
