#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,sum=0,count=0;
	cin>>n;
	long long a;
	char c;
	string str;
	for(long long  i=0;i<n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for(long long j=0;j<a;j++)
		{
			str+=c;
		}
	}
	if(sum%2==0)
	{
        for(long long l=sum-1,r=0;r<=sum/2-1 && l>=sum/2;r++,l--)
		{
			if(str[r]!=str[l])
			{
				count++;
				str[l]=str[r];
			}
		}
	}
	else
	{
		for(long long r=0,l=sum-1;r<(sum-1)/2 && l>(sum-1)/2;r++,l--)
		{
			if(str[r]!=str[l])
			{
				count++;
				str[l]=str[r];
			}
		}
	}
	cout<<count<<endl;
	return 0;
}