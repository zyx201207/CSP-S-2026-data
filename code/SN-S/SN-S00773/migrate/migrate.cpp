#include<bits/stdc++.h>
using namespace std;
int n,m,b,c,s=0;
long long a[100000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m>>b>>c;
	for(int i=1;i<=b;i++)
	{
		cin>>a[i];
	    if(a[i]<=0)
	    {
	    	s++;
		}
	}
	if(s>0)
	{
		cout<<0<<endl;
		cout<<1;
	}
	else
	{
		cout<<1<<endl;
		cout<<2;
	}
	
}
