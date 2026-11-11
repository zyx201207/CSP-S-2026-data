#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b[200005],ans=0;
	string a[200005],j;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		for(int x=1;x<=b[i];x++)
		{
			j+=a[i];
		}
	}
	for(int i=1;i<=j.size();i++)
	{
		if(j[i]!=j[j.size()-i+1])
		{
			ans++;
		}
	}
	return 0;
}
