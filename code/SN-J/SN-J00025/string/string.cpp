#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n;
	cin>>n;
	long long  a[n];
	char b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	if(a[1]=a[2])
	cout<<a[1];
	else
	cout<<"1";
	return 0;
}
