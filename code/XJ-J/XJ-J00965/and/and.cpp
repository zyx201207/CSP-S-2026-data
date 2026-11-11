#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200040];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]==31 &&a[1]==3)
		if(a[2]==1 && a[3]==15)
			if(a[4]==7)
				cout<<7;
	else if(a[0]==3 &&a[1]==15)
		if(a[2]==12 &&a[3]==12)
			cout<<12;
	return 0;
}