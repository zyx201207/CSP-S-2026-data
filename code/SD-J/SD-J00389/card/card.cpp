#include <bits/stdc++.h> 
using namespace std;
int a[10];
int b[10];
int main()
{
	freoprn("card.in","r",stdin);
	freopen("card.ot","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    if(m==1)
    {
    	cout<<n;
	}
	return 0;
}
