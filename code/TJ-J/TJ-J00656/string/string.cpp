#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char a[1000000];
	int t=0,mm=0;
	int num;
	char z;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		cin>>z;
		
		t+=num;
		for(int j=0;j<num;j++)
		{
			a[mm]=z;
			mm++;
		}
	}
//	for(int j=0;j<5;j++)
//		{
//			cout << a[j];
//		}
	int sum=0;
	int ww=t; 
	for(int i=0;i<ww/2;i++)
	{
		if(a[i]!=a[t-1-i])
		{
			a[i]=a[t-1-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

