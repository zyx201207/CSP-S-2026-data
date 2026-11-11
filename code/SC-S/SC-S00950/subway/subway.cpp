#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
using LL=long long;
int c,n,m,d,q;
int w[N],k[N];
int a[505][505],t[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	LL s=0,s2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int i=x;i<=y;i++)
		{
			for(int j=1;j<=k[i];j++){
				s+=a[i][j];
				s2+=t[i][j]; 
			}
		}
		cout<<s<<endl;
	}
	return 0;
}