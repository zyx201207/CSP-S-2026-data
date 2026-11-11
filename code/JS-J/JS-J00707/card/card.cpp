#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f=false;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=true;
		}
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" ";	
		}
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
