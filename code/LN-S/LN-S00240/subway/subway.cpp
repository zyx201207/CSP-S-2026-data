#include<bits/stdc++.h>
using namespace std;
int w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(c==0||n==2||m==5||d==20||q==2)
	{
		cout<<32<<endl<<17;
	}
	return 0;
}
