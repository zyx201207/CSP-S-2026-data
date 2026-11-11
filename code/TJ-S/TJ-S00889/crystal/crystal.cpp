#include<bits/stdc++.h> 
using namespace std;
int n,m,ans;
int a[100000]; 
int num[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int b=0;
		cin>>b;
		if(a[i]<b)
		{
			i++;
		}
		if(a[i]=b)
		{
			ans=ans+1;
			a[i]=num[i];
		}
	}
	cout<<ans;
	return 0;
}




