#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],q,e;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		q+=a[i];
	}
	cout<<q/2-n;
	
	return 0;
}
