#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1]&&m==2)
		{
			int ans=a[i];
			cout<<ans;
		} 
	}
	
	return 0;
}
