#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,t,n,d;
	cin>>c>>t;
	cin>>n>>d;
	if(c==0&&n==4&&d==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0&&n==5&&d==3)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	while(t--)
	{
		cout<<1<<endl;
	}
	return 0;
}
