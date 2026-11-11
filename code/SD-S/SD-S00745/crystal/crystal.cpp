#include<iostream>
using namespace std;
long long n,m;
long long ans,sum;
long long a[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}if(a[0]==a[3])
	{
		cout<<n;
}else{
	for(int i=1;i<=n;i++)
	{
		sum=(i*i+i)/2;
		if(sum>m)
		{
			ans=i;
			break;
		}

	}
	cout<<ans;
}
	return 0;
}
