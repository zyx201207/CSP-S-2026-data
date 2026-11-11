#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200003],u=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>u)
		{
			u=a[i];
		}
	}
	if(m==1)
	{
		cout<<u;
	}
	return 0;
}
