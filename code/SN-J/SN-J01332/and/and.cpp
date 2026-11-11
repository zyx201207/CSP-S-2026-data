#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200005];
	cin>>n>>m;
	int mx=-1;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
