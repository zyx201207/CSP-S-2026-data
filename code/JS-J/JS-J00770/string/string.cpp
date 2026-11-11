#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],cnt=0;
string s[N],o;
bool huiwen(string x)
{
	long long len=x.size();
	for(int i=0;i<len;i++)
	{
		if(x[i]!=x[len-1-i])return 0;
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
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];i++)
		{
			o+=s[i];
		}
			
	}
	if(huiwen(o)==1)cout<<0;
	else cout<<2;
	return 0;
}
