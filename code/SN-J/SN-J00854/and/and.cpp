#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,num;
	int d[200010],f[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		f[i]=d[i] and d[i+1];
		if(num<f[i+1])
		{
			num=f[i+1];
		}
		else
		{
			num=f[i];
		}
	}
	cout<<num;
	return 0;
}
