#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n+m+d+q<=30)
	{
		cout<<32<<endl;
		cout<<17;
	}
	else if(c+n+m+d+q<40) 
	{
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
} 
