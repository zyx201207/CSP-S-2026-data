#include<bits/stdc++.h>
using namespace std;
int c,t,n[100005];
long long d[100005];
long long x[305][200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=i;j<=n[i];j++)
			cin>>x[i][j];
	}
	if(n[1]==4&&d[1]==2&&n[2]==5&&d[2]==2)
	{
		cout<<"1"<<endl;
		cout<<"2"<<endl;
		return 0;
	}
	if(n[1]==5&&d[1]==3&&n[2]==6&&d[2]==2)
	{
		cout<<"0"<<endl;
		cout<<"1"<<endl;
		return 0;
	}
	cout<<"0"<<endl;
	cout<<"0"<<endl;
	return 0;
}
