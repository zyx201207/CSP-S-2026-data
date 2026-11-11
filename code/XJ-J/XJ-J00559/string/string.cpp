#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e7;
char c[N],mp[M];
int n,a[N];
long long int w,ans;
int main()
{
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=w+1;j<=w+a[i];j++)
		{
			mp[j]=c[i];
		}
		w+=a[i];
	}
	for(int i=1;i<=w/2;i++)
	{
		if(mp[i]!=mp[w-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}