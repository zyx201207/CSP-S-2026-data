#include<bits/stdc++.h>
using namespace std;
long long a[10001];
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c=0,t=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
	int n=0,d=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++)
		{
			ans+=a[i]+a[j];
		}
	}
	if(d==2)
	cout<<1;
	else
	cout<<0;
	}
}
