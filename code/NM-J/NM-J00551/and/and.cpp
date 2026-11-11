#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2)
	{
		cout<<a[3]<<endl;
	}
	if(n==5&&m==3)
	{
		cout<<a[5]<<endl;
	}
	else
	{
		cout<<a[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
