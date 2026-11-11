#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,i,ans;
int begin,end;
const int MAXQ=100000;
int Q[2][MAXQ];
int w[100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)
	{
		cin>>w[m];
	}
	ans=w[begin]+w[end];
	return 0;
}
