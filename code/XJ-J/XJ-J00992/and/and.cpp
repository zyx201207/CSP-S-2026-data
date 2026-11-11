#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int b=0;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(a>=b)
			b=a;
	}
	cout<<b;
}
