#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500015],b[500015],c[500015],j,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	cout<<'*';
	sort(a+1,a+1+n);
	a[0]=1145141919810;
	a[n+1]=1145141919810;
	for(int i=1;i<=n+1;i++)
	{
		
		if(a[i]!=a[i-1])
		{
			c[j]=cnt;//cout<<c[j]<<' '; 
			j++;
			cnt=1;
			b[j]=a[i];
			
		}
		else
		{
			cnt++; 
		}
	}
	j--;
	if(j==1)
	{
		cout<<c[1];
		return 0;
	}
//	cout<<'*';
	long long ans=c[1],maxx=0,tm=m,tou=1,chang=c[1],tmpp,kk;
	for(int i=2;i<=j;i++)
	{
		if((ans)*(b[i]-b[i-1])<=tm)
		{
			tm-=(ans)*(b[i]-b[i-1]);
			ans+=c[i];
			maxx=max(maxx,ans);//cout<<maxx<<' '<<c[i]<<' '<<i<<endl;
		}
		else
		{
//			if(m<=c[i-1]*(b[i]-b[i-1]))
//			{
//				ans=m/(b[i]-b[i-1]);
//				tou=i-1;chang=ans;
//				tm=0;
//				maxx=max(maxx,ans);
//			}
//			else if(tm>c[i-1]*(b[i]-b[i-1]))
//			{
				tm-=(ans)*(b[i]-b[i-1]);
				ans+=c[i];
				while(tm<0)
				{
					if(tm+chang*(b[i]-b[tou])<=0)
					{
						tm+=chang*(b[i]-b[tou]);
						tou++;
						ans-=chang;
						chang=c[tou];
					}
					else
					{
						tmpp=-1*tm;
						kk=tmpp/(b[i]-b[tou]);
						if(tmpp%(b[i]-b[tou])!=0) kk++;
						ans-=kk;
						tm+=kk*(b[i]-b[tou]);
						chang-=kk;
					}
				}
//			}
			maxx=max(maxx,ans);//cout<<maxx<<' ';
		}
	}
	cout<<maxx;
	return 0;
}
//5 5
//1 2 4 8 9
