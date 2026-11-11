#include <iostream>
using namespace std;
int a[1001][1001];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j,k,s,t;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>q;
	while(q--) 
	{
		cin>>s>>t;
		
	}
	return 0;
}
