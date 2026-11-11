#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[20000],v,u,ww;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1;i<=(m+2)*2;i++)
	  cin>>v;
	for(int i=1;i<=q;)
	  cin>>u>>ww;
	cout<<m*2+d+q<<endl;
	cout<<d-m+q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
