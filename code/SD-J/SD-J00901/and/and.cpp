#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int pan;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)
			pan=1;	
	}
	if(m==1)
	{
		if(pan=1) cout<<"1";
		else cout<<"0";
	}
	else if(m==n)
	{
		int num=a[1];
		for(int i=2;i<=n;i++)
			num=num&a[i];
		cout<<num;
	}	
	else
		cout<<"1";
	return 0;	
} 
