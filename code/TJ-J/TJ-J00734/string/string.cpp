#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	int a[n];
	string c[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1)	
		cout<<0;
	else if(n==2)
	{
		if(c[0]==c[1])
			cout<<0;
	}
	else{
		for(int i=0;i<n;i++)
		{
			if(a[n]==a[i])
			{
				if(c[n]==c[i])
					s+=0;
				else
				{
					s+=a[i];
				}
			}
			else if(a[n]>a[i])
			{
				if(c[n]==c[i])
				{
					s+=a[n]-a[i];
					a[i+1]-=a[n]-a[i];
				}
				else
				{
					s+=a[n];
					a[i+1]-=a[n]-a[i];
				}
			}
			else
			{
				if(c[n]==c[i])
				{
					s+=a[i]-a[n];
					a[n-1]-=a[i]-a[n];
				}
				else
				{
					s+=a[i];
					a[n-1]-=a[i]-a[n];
				}
			}
			if(i==n)
				break;
			n-=1;
		} 
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
