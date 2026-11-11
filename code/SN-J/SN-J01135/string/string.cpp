#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
string x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			x+=c[i];
		}
	}
	long long lx,t=0,ans=0;
	lx=x.size();
	for(int i=lx-1;i>t;i--)
	{
		if(x[i]!=x[t])
			ans++;
		t++;
	}
	cout<<ans;
	return 0;
}
