#include <iostream>
#include <string>
using namespace std;
int a[1000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	cout<<a[n-1];
	return 0;
}
