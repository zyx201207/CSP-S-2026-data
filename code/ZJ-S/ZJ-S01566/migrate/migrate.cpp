#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while(t--)
	{
		  int n,d;
          int v1=1;
		cin>>n>>d;
		int a[n+1];
		long long sum[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==1)continue;
			if(a[i]-a[i-1]!=a[2]-a[1])v1=0;
			sum[i]=sum[i-1]+1;
		}
		if(v1==1)
		{
			int ans=0;
			if(a[2]-a[1]>d||2*(a[2]-a[1])>d)
			{
				cout<<"1";
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				int k=i+3;
				if(k>n)break;
				ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<"0"<<endl;
	}
	return 0;
}
//1 2 3 4 5 6 d=2;
//
//
//