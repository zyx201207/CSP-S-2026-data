#include<bits/stdc++.h>
using namespace std;
int n,m;
int b=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			b=max(b,x); 
		}
		cout<<b;
	}
	else cout<<0;
	return 0;
}
