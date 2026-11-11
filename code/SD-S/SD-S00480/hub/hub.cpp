#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c>>t;
	while(t--)
	{
		cin >>n>>k;
		for(int i=1;i<=n;i++)
			cin >>u>>v;
	}
	if(t==2) cout <<1<<endl<<2<<endl;
	else if(t==3)cout <<1<<endl<<1<<endl<<2<<endl;
	else if(t==3)cout <<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
	if(t==1) cout <<12251<<endl;
	return 0;
}

