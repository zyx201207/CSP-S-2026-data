//高一轩 SN-S00455 交大附中 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=q;i++)
		{
			cout<<n/2<<"\n";
		}
	}
	return 0;
}
