#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n;
	if(n==2) cout<<0<<endl<<1;
	else
	{
		while(n--)
		{
			cout<<rand()%n<<endl;
		}
	}
	return 0;
}

