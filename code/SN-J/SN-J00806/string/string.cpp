//严禹皓 西安交通大学附属中学 SN-J00806 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long sum=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long k=sum/2;
	string s1="",s2="";
	if(sum%2==0)
	{
		for (int i=1;i<=k;i++)
		{
			s1+=s[i-1];
		}
		for (int i=k+1;i<=sum;i++)
		{
			s2+=s[i-1];
		}
	}
	else
	{
		for (int i=1;i<=k;i++)
		{
			s1+=s[i-1];
		}
		for (int i=k+2;i<=sum;i++)
		{
			s2+=s[i-1];
		}
	}
	long long cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(s1[i-1]!=s2[k-i
		])cnt++;
	}
	cout << cnt;
	return 0;
}
