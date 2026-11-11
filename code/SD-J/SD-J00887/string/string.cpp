#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char k[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>k[i];
		ans+=a[i];
	}
	long long sum=ans/2;
	int i=1;
	int p=0;
	int  l=0;
	while(1)
	{
		sum-=a[i];
		if(sum<=0)
		{
			p=0-sum;
			l=i;
			break;
		}
		i++;
	 } 
	 long long b1=a[l]-p;
	 long long b2=p;
	 if(ans%2==1)
	 {
	 	b1=a[l]-p;
	 	b2=p-1;
	 }
	 long long t=0;
	 
	 long long h=0;
	 for(int i=1;i<=l;i++)
	 {
	 	if(i==l)
	 	{
	 		a[l]=b1;
		 }
	 	while(1)
	 	{
	 		if(n-h==l)
	 		{
	 				b2-=a[i];
	 				if(k[i]!=k[l])
	 				{
	 					t+=a[i];
					 }
					 break;
			 }
	 		if(a[n-h]-a[i]>=0)
	 		{
	 			a[n-h]-=a[i];
	 			if(k[i]!=k[n-h])
			 	{
			 		t+=a[i];
				}
	 			break; 
			 }
			 else
			{
			 	a[i]-=a[n-h];
			 	if(k[i]!=k[n-h])
			 	{
			 		t+=a[n-h];
				}
				h++;
			} 
		 }
	 }
	 cout<<t;
	 return 0;
}
