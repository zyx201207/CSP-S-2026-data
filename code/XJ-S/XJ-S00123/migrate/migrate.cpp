#include <bits/stdc++.h> 
using namespace std;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		long long d;
		cin>>n>>d;
		long long x[n+5];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		long long dd=x[2]-x[1];
		if(d/dd<2) {
		cout<<"0"<<endl;
		continue;
    	}
    	long long l=d/dd*2;
    	if(n<l)
    	{
    		cout<<"0"<<endl;
		}
		else cout<<n-l+1<<endl;
	}
	return 0;
}
