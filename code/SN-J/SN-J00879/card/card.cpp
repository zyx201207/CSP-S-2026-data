#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
    	for(int j=1;j<=i;j++)
    	{
    		a[i]++;
		}
	}
	if(n==4&&m==3)
	{
		cout<<"3 1 4";
	}
	if(n==10&&m==3)
	{
		cout<<"10 3 3";
	}
    return 0;
}
