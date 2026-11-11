#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long y=a[2]-a[1],r=y;
	int l=0,t=0;
	for(int i=2;i<=n;i++)
	{
		y+=a[i+1]-a[i];
		r=y;
	    if(r>m)
	    {
	    	t=i;
	    	break;
		}
	}
	cout<<t;
    return 0;	
} 
