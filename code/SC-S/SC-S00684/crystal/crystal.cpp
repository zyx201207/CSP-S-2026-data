#include<iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[1000000];
	long long n,m,num,num_1;
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		num+=a[i];
		num_1+=1;
	}
	cout<<num/num_1;
	return 0;
}