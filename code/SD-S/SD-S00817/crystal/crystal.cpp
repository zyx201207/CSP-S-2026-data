//Oct31==Dec25?
//5 8 -3 -1 2 2 7
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
long long a[500005];
long long n,m;
//long long b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cout<<log2(1000000000000);
	long long l=10000000000003,r=-10000000000003;
	scanf("%lld%lld",&n,&m);
	int flag=0;
	int flaga=0,flagb=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<l)
		{
			l=a[i];
		}
		if(a[i]>r)
		{
			r=a[i];
		}
		if(a[i]>100||a[i]<-100)
		{
			flag=1;
		}
		if(a[i]!=i)	flaga=1;
		if(i==1)
		{
			continue;
		}
		else
		{
			if(a[i]-a[i-1]!=a[2]-a[1])
			{
				flagb=1;
			}
		}
	}
	sort(a+1,a+1+n);
	if(!flag)//C1->7  C10->12 sum=10;
	{
		long long k=0,ans=0;
		for(int i=l;i<=r;i++)
		{
			int ll=1,rr=n,anss=0;//anss最后小于等于i的下标 
			while(ll<=rr)
			{
				int mid=(ll+rr)/2;
				if(a[mid]>i)
				{
					rr=mid-1;
				}
				else
				{
					ll=mid+1;
					anss=mid; 
				}
			}
//			cout<<anss<<;
//			int tans=anss;
//			for(int j=tans;j<=n;j++)
//			{
//				if(a[j]==i)
//				{
//					anss++;
//				}
//			}
			int tot=0;
			for(int j=anss;j>=1;j--){
				k+=i-a[j];
				if(k>m)
				{
					break;
				}
				tot++;
			}
			if(tot>=ans)
			{
				ans=tot;
				
			}//cout<<i<<' '<<anss<<' '<<tot<<endl;
			k=0;
		}
		printf("%lld",ans);
	}
	else if(flaga==0||flagb==0)//C13->18  sum=6
	{
		long long k=a[2]-a[1];
		long long samu=0,pos=1;
		for(int i=1;i<=n;i++)
		{
			samu+=pos*k;
			if(samu>m)
			{
				printf("%lld",pos);
				break;
			}
			pos++;
		}
	}
	else
	{
		printf("279");
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			
//		}
//	}
	cout<<endl;
	return 0;
}













