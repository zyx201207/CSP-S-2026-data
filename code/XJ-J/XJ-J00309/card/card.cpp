#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],k[8],l[8];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==1)
	{
		cout<<n<<endl;
		cout<<n-1<<endl;
	}
	else
	{
		cout<<n-1<<endl;
		cout<<n<<endl;
	}
}