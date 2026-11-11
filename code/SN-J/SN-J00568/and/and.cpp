#include<bits/stdc++.h.>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int a[200001]={0};
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	int b=a[m-1];
	for(int i=1;i<n;i++)
	{
		b=b&a[m-1-i];
	}
	cout<<b;
	return 0;
}
