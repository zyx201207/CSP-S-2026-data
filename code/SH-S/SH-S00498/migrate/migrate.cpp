#include<bits/stdc++.h>
using namespace std;
int a[2000005]
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){cin>>a[i];}
		cout<<a[n/2]<<endl;
	}
	return 0;
	
}
