#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int cnt,n,ans,m;
	cin>>a>>b>>c>>d;
	if(a[1] == c[1] && a[0] == c[0])
	{
		cout << 1;
	}
	if(b[1] == d[1] && b[0] == d[0])
	{
		cout << 1;
	}
	

	return 0;
}
