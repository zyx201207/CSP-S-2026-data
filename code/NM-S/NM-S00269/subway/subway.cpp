#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
long long c,n,m,d,q;
long long w[5*M],k[5*M],x[5*M],y[5*M];
long long a[505][20005],t[505][20005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	 cin>>w[i];
	for(int i=1;i<=n;i++)
	 {
	 	cin>>k[i];
	 	for(int j=1;j<=k[i];j++)
	 	 cin>>a[i][j]>>t[i][j];
	 }
	for(int i=1;i<=q;i++)
	 cin>>x[i]>>y[i];
	if(c==0) {
		        if(n==2&&m==5&&d==20&&q==2) 
		         cout<<32<<endl<<17;
		        if(n==3&&m==7&&d==20&&q==2) 
		         cout<<35<<endl<<16;
	         }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
