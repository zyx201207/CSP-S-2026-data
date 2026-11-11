#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[3];
	int c[1000000];
	int n;
	cin>>n;
	if(n<=1)	{
	cout<<0;
	
}
    if(n==2)
    {
    	cin>>a[1]>>c[1]>>a[2]>>c[2];
		cout<<min(a[1],a[2]) ;
	}
	
	
	
	
	
	return 0;
	
}
