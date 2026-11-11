//zbh aoxiang 00497  //      or sum_1+(i-1)*a[i]<0


//	for(int i=zb;i>=0;i--)
//	{
//		if(sum_1+(i-1)*a[i]>m) 
//		{
//			ans1=zb-i+1;
//			break;	
//		}
//		sum_1=sum_1+(i-1)*a[i];
//	}
#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005],a_1[500004],ans1,ans2;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a_1[i];
	}
	sort(a_1+1,a_1+1+n);
	long long zb;
	if(n%2==0) zb=n/2;
	else zb=(n+1)/2;
	a[1]=a_1[1];
	long long sum_1=0,sum_2=0; 
	for(int i=2;i<=n;i++)
	{
		a[i]=a_1[i]-a_1[i-1];
	}
	for(int i=zb;i>=2;i--)
	{
		//te
		if(sum_1+(i-1)*a[i]<=m and i==2)
		{
			for(int j=zb+1;j<=n;j++)
			{
				//cout<<sum_1<<' '<<i<<' '<<1<<endl;
				if(sum_1+(j-zb)*a[j]>=m or j==n and sum_1!=0)
				{
					//cout<<j<<' '<<zb<<endl;
					ans1+=j-zb;
					break;	
				}
				sum_1=sum_1+(j-zb)*a[j];
			}
			break;
		}
		//ture
		if(sum_1+(i-1)*a[i]>m) 
		{
			ans1=zb-i+1;
			break;
		}
		ans1++;
		sum_1=sum_1+(i-1)*a[i];
	}
	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
	for(int i=zb+1;i<=n;i++)
	{
		
		
		if(sum_2+(i-zb)*a[i]<=m and i==n and sum_2!=0)
		{
			for(int j=zb;j>=2;j--)
			{
				if(sum_2+(i-1)*a[i]>=m or j==0) 
				{
					ans2+=zb-j+1;
					break;	
				}
				sum_2=sum_2+(j-1)*a[j];
			}
			break;
		}
		
		
		if(sum_2+(i-zb)*a[i]>m) 
		{
			ans2=i-zb;
			break;	
		}
		ans2++;
		sum_2=sum_2+(i-zb)*a[i];
	}
	cout<<max(ans1,ans2);
	return 0;
}
