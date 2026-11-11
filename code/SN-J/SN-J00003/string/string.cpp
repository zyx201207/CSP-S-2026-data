#include <iostream>
using namespace std;
int main()
{
	int n,num=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x,v;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>v;
		num+=x;
	}
	cout<<num/2;
}
