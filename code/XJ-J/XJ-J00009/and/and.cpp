#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main()
{
	//freopen("travel","r",stdin);
	//freopen("travel","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a-1;
	long long sum=a[n];
	for(int i=a;i<=n-1;i++){
		ans
	}

	cout<<sum<<endl;
	return 0;
}