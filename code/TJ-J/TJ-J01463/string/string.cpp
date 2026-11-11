#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char b;
		char t;
		cin>>b>>t;
		char c=b*t;
		if(c/2>t)
		{
			ans++;
		}
	}
	cout<<ans;s
	 return 0;
}
