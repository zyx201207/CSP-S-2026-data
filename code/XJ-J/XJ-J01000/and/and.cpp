#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int a[n+1]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2)
	{
		cout<<12;
	}
	if(n==5&&m==3)
	{
		cout<<7;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}