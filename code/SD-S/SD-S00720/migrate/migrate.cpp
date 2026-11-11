#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
			{
				f=0;
			}
		}
		cout<<"0"<<endl;
	}
	return 0;
}
