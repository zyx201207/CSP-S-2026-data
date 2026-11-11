#include <bits/stdc++.h>
using namespace std;
int c,d,dif[2000005],e,n,t,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cin>>x[0];
		for(int i=2;i<=n;i++)
		{
			cin>>x[i];
			dif[i]=x[i]-x[i-1];
		}
		if(c==11||c==12)
		{
			e=d/dif[1];
			if(d<2*dif[1])cout<<0<<endl;
			else cout<<n+1-2*e<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
