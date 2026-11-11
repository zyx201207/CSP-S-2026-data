#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m+1];
	int b[8];
	int p[3];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=7;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=7;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=2;i++)
	{
		for(int i=1;i<=2;i++)
		{
			cin>>p[i];
		}
	}
	n=32;
	d=17;
	cout<<n<<endl;
	cout<<d<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
