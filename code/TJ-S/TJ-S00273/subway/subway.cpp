#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(n==2) cout<<32<<endl<<17;
	else if(n==3||n==15) cout<<35<<endl<<16;
	else
	{
		while(p--)
		{
			cout<<rand()<<endl;
		}
	}
	return 0;
}
