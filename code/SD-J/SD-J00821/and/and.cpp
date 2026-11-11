#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[100000];
	cin>>n>>m;
	set<string>S;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i+1])
		{
			a[i]=a[i+1];
			return a[i];
		}
	}
	cout<<a[m+1];
	return 0;
}


