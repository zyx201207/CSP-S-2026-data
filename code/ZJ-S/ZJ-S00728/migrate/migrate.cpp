#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,sum,o=1;
int a[2000005],s[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int t1=t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sum=n+1-(1.5*d);
		s[o]=sum;
		o++;
	}
	for(int j=1;j<=t1;j++)
	{
		cout<<s[j]-1<<endl;
	}
	return 0;
}