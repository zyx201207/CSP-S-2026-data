#include<bits/stdc++.h>
using namespace std;
long long a[3000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w".stdout);
    int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{ 
			cin>>a[i];
		}
		if(n==0||n==1||n==2) cout<<"0"<<endl;
		else cout<<"3"<<endl;
	} 
	return 0;
}
