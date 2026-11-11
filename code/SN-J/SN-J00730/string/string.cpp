//张宸铭 西安辅轮中学 SN-J00730 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen('string.in','r' stdin)
	freopen('string.out','w' stdout)
	int a[300000],n;
	string b[3000000];
	long long c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		c+=a[i];	
	} 
	int num=0;
	int i=1;
	int m=n;
	while(i<n)
	{
		if(i==m)
		{
			cout<<num;
			return 0;
		}
		if(i==m-1&&a[i]==a[m])
		{
			if(b[i]!=b[m])
			{
				num+=a[i];
			}
			cout<<num;
			return 0;
			
		}
		if(b[i]!=b[m])
		{
			if(a[i]>a[m])
			{
				a[i]-=a[m];
				num+=a[m];
				m--;
			}
			else if(a[m]>a[i])
			{
				a[m]-=a[i];
				num+=a[i];
				i--;
			}
			else
			{
				a[m]=0;
				a[i]=0;
				num+=a[i];
				i--;
				m--;
			}
		}
		else
		{
			if(a[i]>a[m])
			{
				a[i]-=a[m];
				m--;
			}
			else if(a[m]>a[i])
			{
				a[m]-=a[i];
			
				i--;
			}
			else
			{
				a[m]=0;
				a[i]=0;
				i--;
				m--;
			}
		}
	}
}
