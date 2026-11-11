#include<bits/stdc++.h>
#define F10 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
using namespace std;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	F10
	ull n;
	std::cin>>n;
	ull l=0;
	for(ull i=0;i<n;i++)
	{
		ull x;
		std::cin>>x;
		char y;
		std::cin>>y;
		for(ull i=l;i-l<x;i++)
		{
			a[i]=y;
		}
		l+=x;
	}
	ull s=0;
	for(ull i=0,j=l-1;i<j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			s++;
		}
	}
	std::cout<<s;
	return 0;
}
