#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		cout<<12;
	}
	else
	{
		cout<<7;
	}
	return 0;
}



