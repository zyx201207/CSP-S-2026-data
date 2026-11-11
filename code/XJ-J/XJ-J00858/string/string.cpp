#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,i,j,d,l=0,num=0,flag=0;
	string s,a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d>>a;
		for(j=1;j<=d;j++)
		{
			s=s+a;
		}
	}
	l=s.size();
	long long int r;
	r=l;
	while(r!=0)
	{
		for(i=0;i<l;i++)
		{ 
			r--;
			a[r]=s[i];
			
		}
	}
	for(i=0;i<l;i++)
	{
		if(a[i]!=s[i])
		flag++;
	}
	cout<<flag;
	return 0;
}