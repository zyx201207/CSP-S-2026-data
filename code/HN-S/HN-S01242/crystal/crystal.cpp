#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,p=0;
	cin>>n>>m; 
	int a[(n+5)];
	for(int i1=0;i1<n;i1++)
	{
		cin>>a[i1];
		p=p+a[i1];
	}
	p=p/n;
	/*cout<<endl;
	
	for(int i2=0;i2<n;i2++)
	{
		cout<<a[i2];
	}*/
	
	
	return 0;
}

