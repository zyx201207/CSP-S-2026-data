#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	int s[100000]={0};
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	for(int j=n;j>n-m;j--)
	{
		ans=min(s[j],s[j-1]);
	}
	cout<<ans;
	return 0;
}

