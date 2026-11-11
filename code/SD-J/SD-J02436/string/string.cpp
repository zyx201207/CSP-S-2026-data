#include<bits/stdc++.h>
using namespace std;
int n; 
int a[200005];
string c[200005];
string s;
long long int ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(long long int j=1;j<=a[i];j++)
		s+=c[i];
	}
	
	long long int sum=s.size();
	
	for(long long int i=0;i<sum/2;i++)
	{
		long long int j=sum-i-1;
		
		if(s[i]!=s[j])
		ans++;
	}
	
	cout<<ans;
	return 0;
}
