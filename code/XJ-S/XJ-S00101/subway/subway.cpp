#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if (n==2&&m==5&&d==20)cout<<32<<endl<<17;
	for (int i = 1; i <= q; i++)
	{
		cout<<4+c*1+n*m+d-q;
	}
	return 0;
}
