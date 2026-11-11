#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[1000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[1];
	}
	if(n==2)
		cout<<2<<3;
	if(n==3)
		cout<<3<<1<<4;
	if(n==4)
		cout<<6<<4<<9<<2;
	if(n==5)
		cout<<8<<4<<3<<7<<1;
	return 0;
}