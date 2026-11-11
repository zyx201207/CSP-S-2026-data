#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200010];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m];
	return 0;
}
