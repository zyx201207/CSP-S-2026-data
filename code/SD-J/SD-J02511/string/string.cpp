#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200001],m=0;
	char c[200001],b[200001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		int z=c[i]*a[i];
		m=m+z; 
	}
	if(n==1||n==2&&c[1]==c[2]||n==2&&a[1]%2!=0&&a[2]%2!=0)
	{
		cout<<"0";
		return 0;
	}
	if(n==2&&a[1]==a[2])
	{
		cout<<a[1];
		return 0;
	}
	cout<<m;
	return 0;
}
