#include<bits/stdc++.h>
using namespace std;

int a[4];
int main()
{
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int w,m,n;
	string a,b;
	cin>>w;

	if(w==1)
	{
	  cin>>a[1]>>a;
	  cout<<"0";
	}
	if(w==2)
	{
		
		
			cin>>m>>a>>n>>b;
		
		
	
		if(m==n) cout<<m;
		if(m<n) cout<<m;
		if(m>n) cout<<n;
	
	}
	return 0;
}
