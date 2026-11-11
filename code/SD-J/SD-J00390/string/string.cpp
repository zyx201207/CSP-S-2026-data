#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,l,l1,f;
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(n==1) 
		{
			cout<<0;
			return 0;
		}
		l+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	
	if(l%2==0) l1=l/2;
	else l1=l/2+1;
	for(int i=0;i<l1;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			s[l-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
