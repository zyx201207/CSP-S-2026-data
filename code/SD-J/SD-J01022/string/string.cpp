#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=2e5+5;
char a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll cnt=1,x=0;
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>x>>s;
		a[cnt]=s;
		cnt+=x;
	} 
	char c;
	string s;
	for(int i=1;i<cnt;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			c=a[i];
		}
		s+=c;
	}
	ll ans=0;
	int len=s.size();
	len/=2;
	for(int i=0,j=len*2-1;i<len;i++,j--)
	{
		if(s[i]!=s[j])
		{
			ans++;	
		}	
	}
	cout<<ans;
	return 0;
} 
