#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ks,ans,xl[2000005],xr[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;x[i]-x[j]<=d;j--)
		{
			xl[i]=j;
		}
		for(int j=i+1;x[j]-x[i]<=d;j++)
		{
			xr[i]=j;
		}
	}
	for(int i=1,j=4;j<=n;j++)
	{
		while(xr[i]-xl[j]!=1 && i<j-2)i++;
		if(xr[i]-xl[j]==1)ans++;
	}
	cout<<ans<<'\n';
	ans=0;
	}return 0;
}
/*
cd ..
cd migrate
g++ -O2 -std=c++14 -static migrate.cpp -o migrate
time ./migrate

*/