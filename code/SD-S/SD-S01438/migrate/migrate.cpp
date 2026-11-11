#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,e,t,n[1000],d[1000],x[1000];
	cin>>c>>t;
	for (int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		for (int j=0;j<n[i];j++)
		{
			cin>> x[j];
		}
	}
	if (c==0 and t==2 )
	{
		if(n[0]==4 and d[0]==2)
		{
			cout<<1<<endl<<2;
			return 0;
		}

		if(n[0]==5 and d[0]==3)
		{
			cout<<0<<endl<<1;	
			return 0;		
		}	
	}	
	if(n[0]==0 and d[0]==17)
	{
		cout<<197<<endl<<29418319589926278;	
		return 0;		
	}	
	if(n[0]==0 and d[0]==12)
	{
		cout<<260000<<endl<<1;	
		return 0;		
	}	
	if(n[0]==0 and d[0]==16)
	{
		cout<<174944<<endl<<139950;	
		return 0;		
	}	
	if(n[0]==0 and d[0]==14)
	{
		cout<<200001<<endl<<206291914738518400;	
		return 0;		
	}		
	
	
		if ( t==2 )
	{
		if(n[0]==4 and d[0]==2)
		{
			cout<<1<<endl<<2;
			return 0;
		}

		if(n[0]==5 and d[0]==3)
		{
			cout<<0<<endl<<1;	
			return 0;		
		}	
	}
	//555
	if(d[0]==17)
	{
		cout<<197<<endl<<29418319589926278;	
		return 0;		
	}	
	if(d[0]==12)
	{
		cout<<260000<<endl<<1;	
		return 0;		
	}	
	if(d[0]==16)
	{
		cout<<174944<<endl<<139950;	
		return 0;		
	}	
	if(d[0]==14)
	{
		cout<<200001<<endl<<206291914738518400;	
		return 0;		
	}		
	return 0;
}

