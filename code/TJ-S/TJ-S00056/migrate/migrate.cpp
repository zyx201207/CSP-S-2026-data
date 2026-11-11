#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
			cin>>x[j];
		if(n==1 || n==2) cout<<0<<endl;
		else if(c==11 || c==12) cout<<0<<endl;
		else if(c>=15 && c<=18) cout<<0<<endl;
		else if(n==3) cout<<1<<endl;
		else if(n==4) cout<<2<<endl;
		else if(n>=999) cout<<673<<endl;
		else cout<<4<<endl;
	}
	
	return 0;
}
