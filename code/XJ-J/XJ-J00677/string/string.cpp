#include<bits/stdc++.h>
using namespace std;
long long int n,a[20005],t=0,ans,r,l;
string s;
char c[20005];
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
	for(int j=1;j<=a[i];j++)
	{
		s+=c[i];
		t++;
	}
	for(r=t-1,l=0;r>=t/2,l<=t/2;r--,l++)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 