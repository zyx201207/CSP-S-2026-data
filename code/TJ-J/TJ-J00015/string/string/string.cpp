#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s;
	int n,a[10005],c[10005];
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i<a[i];i++)
	{
		cin>>c[i];
		if(a[i]==c[i]||a[i]!=c[i])
		{
			a[n]++;
		}
		if(a[n]==c[n]||a[n]!=c[n])
		{
			c[n]++;
		}
	}
	cout<<a[n]<<" "<<c[n]<<endl;
	return 0;
}
