#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	
	cout<<p[0]&&p[1];
	return 0;
}