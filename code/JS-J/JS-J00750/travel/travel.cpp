#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,g,h;
char e,f;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a!=c) cout<<"0000"<<endl;
	else
	{
		if(b!=d) cout<<"1000"<<endl;
		else
		{
			g=e-'A'+1;
			h=f-'A'+1;
			if(abs(g-h)==1&&e!='C'&&f!='C') cout<<"1111"<<endl;
			else if(abs(g-h)==2&&(e=='A'||f=='A')) cout<<"1110"<<endl;
			else cout<<"1100"<<endl;
		}
	}
	return 0;
}
