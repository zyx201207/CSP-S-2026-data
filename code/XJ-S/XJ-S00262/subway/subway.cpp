#include<bits/stdc++.h>
using namespace std;
int M[100005];
int k[100005];
int x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ki,r;
	cin>>c>>n>>m>>d>>q;
	for(int a=1;a<=m;a++) cin>>M[a];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=i+2;j++)
		{
			cin>>ki;
			cin>>k[j];
		}
	}
	cin>>x>>y;
	for(int a=1;a<=m;a++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=i+2;j++)
			{
				cout<<M[a]+k[j]+k[j+1]+M[a+1];
			}
		}
	}
	return 0;	
}
