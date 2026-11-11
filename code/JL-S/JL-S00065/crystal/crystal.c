include<bits/stdc++.h>
using namespace std;
int a[1000000000000];
int main()
{
	int n;
	long long m;
	cin>>n,m;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int b=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		int x=a[i+1]-a[i];
		if(x<m)
		{
			for(int j=i;j>=0;j--)
			{
				m=m-x;
				if(m>=0)
				{
					sum++;
					a[j]=a[j]+x;
				}
				else{
					break;
				}
			}
		}
		for(int j=i+1;=n;j++)
		{
			if(a[i]==a[j])
			{
				sum+=1;
			}
		}
		b=max(b,sum);
	}
	cout<<b;
	return 0;
}
