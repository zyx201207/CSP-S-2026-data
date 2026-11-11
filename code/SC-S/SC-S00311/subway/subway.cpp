#include<bits/stdc++.h>
using namespace std;
int a,b;long long c,d,h,k[2000010],o[100000],e;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++)
	{
		cin>>k[i];
	}for(int i=1;i<=b;i++)
	{
		cin>>h;for(int i=1;i<=h;i++)cin>>o[i]>>o[i];
	}int n,m;for(int i=1;i<=e;i++)
	{
		cin>>n>>m;
		cout<<k[n]+k[m]+o[n]+o[m]<<"\n";
	}
	return 0;
}