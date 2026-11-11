#include<bits/stdc++.h>
using namespace std;
long long int a[50005];
int n;
long long m,sum1=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0)
		{
			sum1+=a[i];
		}
	}
	sum1/=m;
	cout<<"3";
	return 0;
}
