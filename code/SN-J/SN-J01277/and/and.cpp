#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10000000]={};
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<a[0];
	
	return 0;
	
}

