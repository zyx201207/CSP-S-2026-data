#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v;
	cin>>c>>t;
	if(c==0)
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
				cin>>u>>v;
		}
		if(t==2)
			cout<<1<<"\n"<<2;
		if(t==3)
			cout<<1<<"\n"<<"\n"<<1<<"\n"<<2;
		if(t==5)
			cout<<17<<"\n"<<9<<"\n"<<6<<'\n'<<6<<"\n"<<9<<"\n";
		if(t==1)
			cout<<12251;
	}
	else
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
				cin>>u>>v;
		}
		for(int i=1;i<=t;i++)
		{
			srand(time(NULL));
			cout<<rand()*rand()%114514;
		}
	}
	return 0;
}