#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	long long sum=0,n,i,t,cnt=0;
	string s="0";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		sum+=a[i];
		t=a[i];
		while(t--)
		{
			s+=c;
		}
	}
	for(i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i+1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
 } 
