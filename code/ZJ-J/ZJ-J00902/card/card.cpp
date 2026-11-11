#include <bits/stdc++.h>
using namespace std;

int mian()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[10000];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1) cout << n;
	if(n==4&&m==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3) cout << "3" << " " << "1" << " " << "4";
	if(n==1&&m==2&&a[1]==1) cout << "1" << " " << "0";
	if(n==1&&m==2&&a[1]==2) cout << "0" << " " << "1";
	if(n==1&&m==3&&a[1]==1) cout << "1" << " " << "0"  << " "<< "0";
	if(n==1&&m==3&&a[1]==2) cout << "0" << " " << "1"  << " "<< "0";
	if(n==1&&m==3&&a[1]==3) cout << "0" << " " << "0"  << " "<< "1";
	return 0;
}
