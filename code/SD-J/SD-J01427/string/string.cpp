#include<iostream>
using namespace std;
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	int m;
	string s2,s3;
	char s1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		cin>>s1;
		for(int j=0;j<=m;j++)
		{
			s2[j]=s1;
		}
		m=0;
	}
	for(int i=s2.size();i>=0;i--)
	{
		s3[i]=s2[i];
	}
	for(int i=0;i<=s3.size()/2;i++)
	{
		if(s3[i]!=s3[0-i])
		{
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
