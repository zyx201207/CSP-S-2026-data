#include<bits/stdc++.h>
using namespace std;
char s1[100000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int sum=0;
	cin>>n;
	int st=1;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		sum+=a;
		char s;
		cin>>s;
		for(int j=st;j<st+a;j++)
		{
			s1[j]=s;
		}
		st+=a;
	}
	int res=0;
	for(int i=1;i<=sum;i++)
	{
		if(s1[i]!=s1[sum+1-i])res++;
	}
	cout<<res/2;
	return 0;
}
