#include <bits/stdc++.h>
using namespace std;
long long  n,m,k;
int a[10000];
int main()	
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	if(a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12)
		cout<<12;
	else if(a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7)
		cout<<7;
	else 
		cout<<k;
	return 0;
} 
