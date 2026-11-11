#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
long long num=0;
int a[100000];
char b[100000];
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
			num++;
		}
		
	}
	for(int i=0;i<num;i++)
	{
		if(s[i]!=s[num-i-1])
		{
			sum++;
		}
		if(i==num/2-1)
		{
			break;
		}
	}
	cout<<sum;
	return 0;
}
