#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=5e5+10;
ll n,m;
ll a[MAX_N],mton[MAX_N],ton[MAX_N]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ton[a[j]]++;
		 } 
	}
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<ton[i]<<' ';
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
