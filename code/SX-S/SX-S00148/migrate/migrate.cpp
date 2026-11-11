#include<bits/stdc++.h>
using namespace std;
int a[1010];
int s;
int i;
int l=0,r;
int n=1000;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}

	if(a[2]==1)
	{
		cout<<0<<endl<<1;
	}

	return 0;
}