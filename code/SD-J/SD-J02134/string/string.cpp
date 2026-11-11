#include<bits/stdc++.h>
using namespace std;
string q;
int w;
string s;
int a[1000009],d[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>w>>q;
		while(w--)
		{
			s+=q;
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	int sum=s.size()-1;
	int i=0;
	for(int j=sum;j>=0;j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
		if(s[i]==s[j])
		{
			sum=j;
		}
		if(j-i==1||j==i)
		{
			cout<<cnt;
			return 0;
		}
		i++;
	}
}
