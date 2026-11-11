#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long sum=0,zd=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(m==2)
		{
			sum=a[1]&a[2];
		}
		else{
			sum=a[1]&a[2];
			for(int j=3;j<=m;j++)
			{
				sum=sum&a[j];
			}
		}
		if(zd<sum)
		{
			zd=sum;
		}
	}
	cout<<sum;
	return 0;
}
