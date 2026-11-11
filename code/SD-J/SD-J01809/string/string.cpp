#include<bits/stdc++.h>
using namespace std;
long long n,a,q;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a/2;j++)
		{
			s+=c;
		}
	}
	long long l,r,ans=0,q=s.size();
	if(q%2!=0)
	{
		l=q/2-1;
		r=q/2+1;
	}
	else
	{
		l=q/2-1;
		r=q/2;
	}
	for(int i=1;i<=q/2;i++)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l--;
		r++;
	}
	cout<<ans*2;
	return 0;
}
