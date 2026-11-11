#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char x[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		int j;
		for(j=1;j<=a[i];j++)
		{
			s+=x[i];
		}
	}
	long long l=s.size();
	long long ans=0;
	if(l%2==0)
	{
		long long cnt=l/2;
		string m="";
		for(long long i=0;i<cnt;i++)
		{
			m+=s[i];
		}
		int j=0;
		for(long long i=l-1;i>=cnt;i--)
		{
			if(s[i]!=m[j])
			{
				ans++;
			}
			j++;
		}
		cout<<ans;
	}
	else
	{
		long long cnt=(l+1)/2;
		string m="";
		for(long long i=0;i<cnt;i++)
		{
			m+=s[i];
		}
		int j=0;
		for(long long i=l-1;i>=cnt-1;i--)
		{
			if(s[i]!=m[j])
			{
				ans++;
			}
			j++;
		}
		cout<<ans;
	}
	return 0;
}