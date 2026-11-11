#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long j=0,a;
	char b;
	string s;
	for(int i=0;i<=n;i++)
	{
		cin>>a>>b;
		if(a==b)
		{
			j+=1;
		}
	}
	cout<<j;
	return 0;
}
