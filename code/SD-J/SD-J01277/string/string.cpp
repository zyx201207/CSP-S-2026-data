#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
long long sum=0,ans=0;
string s;
bool pd(string x)
{
	for(int i=sum-1;i>=0;i--)
	{
		if(x[i]!=x[sum-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	if(pd(s))
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<(sum+1)/2;i++)
	{
		if(s[i]!=s[sum-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;	
} 
