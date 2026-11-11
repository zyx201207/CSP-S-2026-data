#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
long long c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c>>t;
	for(int i = 1;i <= t;i++)
    {
		if(i % 2 == 0)
		{
			cout<<0<<'\n';
		}
		else 
		{
			cout<<1<<'\n';
		}
	}
	return 0;
}
