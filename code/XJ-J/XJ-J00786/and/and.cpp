#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,Max=-1;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int t;
		cin>>t;
		Max=max(t,Max);
	}
	cout<<Max;
	return 0;
}

