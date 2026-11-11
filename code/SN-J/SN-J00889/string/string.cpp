#include<bits/stdc++.h>
using namespace std;
char s1[100000000000010];
char s2[100000000000010];
char s3[100000000000010];
int n;
int a;
char c;
int k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			k++;
			s1[k]=c;
		}
	}
	int mid=k/2;
	for(int i=1;i<=mid;i++)
	{
		s2[i]=s1[i];
	}
	int num;
	if(k%2==0)
	{
		num=mid;
	}
	else
	{
		num=mid+1;
	}
	int o=0;
	for(int i=num+1;i<=k;i++)
	{
		o++;
		s3[o]=s1[i];
	}
	int w=0;
	for(int i=1;i<=o;i++)
	{
		if(s3[i]!=s2[i])
		{
			w++;
		}
	}
	cout<<w;
	return 0;
}
