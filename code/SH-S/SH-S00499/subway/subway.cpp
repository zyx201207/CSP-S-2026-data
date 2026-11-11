#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int a[100][100],b[100][100],k,c,n,m,d,q,tz[1000],tb[100][100],mb[10][100],ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>tz[i];
	}
	for(int i=0;i<n;i++)
	{
	cin>>k;
	for(int j=0;j<k;j++)
	{
				cin>>a[i][j];
				cin>>tb[i][j];
			}}
	for(int i=0;i<q;i++)
	{
		cin>>mb[i][0]>>mb[i][1];
		
	}
	for(int i=0;i<q;i++)
	{
		ans=tz[mb[i][0]-1]+tz[mb[i][1]-1];
		cout<<ans<<endl; 
	}
	

	return 0;
}
