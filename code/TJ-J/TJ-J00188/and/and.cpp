#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m=0;
	cin >>n;
	string a;
	int aa;
	for(int i=1;i<=n;i++)
	{
		cin >>aa;
		a+=aa;
		m=max(m,aa);
	}
	cout <<m;
}
