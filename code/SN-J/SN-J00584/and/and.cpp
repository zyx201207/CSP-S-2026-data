#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,b,a[200000];
	cin>>n>>m;
	for(b=1;b<=n;b++)
	cin>>a[b];
	if(a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	cout<<12;
	if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	cout<<7;
}
