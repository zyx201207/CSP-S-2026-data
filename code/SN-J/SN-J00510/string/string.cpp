#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
    sort(a[0],a[100001]);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
