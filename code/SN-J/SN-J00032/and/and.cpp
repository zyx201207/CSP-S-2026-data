#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a>b>c>d)
	cout<<a;
	if(b>c>d>a)
	cout<<b;
	if(c>d>b>a)
	cout<<c;
	if(d>c>a>b)
	cout<<d;
	return 0;
	
}
