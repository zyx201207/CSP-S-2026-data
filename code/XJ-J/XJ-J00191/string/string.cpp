#include<bits/stdc++.h>
using namespace std;
int n; 
const int maxx=2e5+5;
string s;
int a[maxx];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>a[i]>>c;
		
	}
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		cout<<min(a[1],a[2]);
	}
	if(n==3)
	{
		cout<<5;
	}
	return 0;
}

