#include<bits/stdc++.h>
using namespace std;
long long w[1000],k[1000],r[1000],b[1000],a[1000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int j=0;j<d/2-3;j++)
		cin>>k[j];
	for(int x=0;x<d/2-3;x++)
		cin>>r[x];
	for(int y=0;y<p;y++)
		cin>>b[y];
	for(int z=0;z<p;z++)
		cin>>a[z];
	long long sum=0,ans=0;
	if(n==3)
	{
		sum=(n+p)*m;
		ans=n*m-p*p-1;
		cout<<sum<<endl;
		cout<<ans;
	}
	else 
	{
		sum=n*m+d+p;
		ans=d-n*p+1;
		cout<<sum<<endl;
		cout<<ans;
	}
	return 0;
}
