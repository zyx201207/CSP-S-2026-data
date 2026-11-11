#include <iostream>
#include <csrdio>
using namespace std;
int c,n,m,d,q,w[1005],k,t[505][1005],a[100005][2],ans[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
			cin>>[i][j];
	}
	for(int i=0;i<q;i++)
		cin>>a[i][0]>>a[i][1];
	cout<<m<<endl<<q<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
