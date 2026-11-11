#include<bits/stdc++.h>
using namespace std;
void fre(){

freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
}
int c,t;
int n,d;
long long x[10000010];
int min_x[100000010];
int main()
{
	fre();
cin>>c>>t>>n>>d;
fre();
for(int l=1;l<=t;l++)
{
	if(d==1)
{
	cout<<0;
}
	cin>>x[1];
	for(int i=2;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==2)
	cout<<0;
	else
	{for(int i=n;i>=1;i--)
	{
		if(x[i]-x[i-2]>=d)
		cout<<1;
		continue;
	}
		cout<<0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}










return 0;
}

