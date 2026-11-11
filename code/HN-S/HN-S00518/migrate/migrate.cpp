#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,a[2000005];
	cin>>n>>d;
	for(int i=0;i>n;i++) cin>>a[i];
	cout<<n-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
