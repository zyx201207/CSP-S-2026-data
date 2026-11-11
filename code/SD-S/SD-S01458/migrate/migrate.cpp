#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[10001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
	    cin>>n>>d;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>x[i];
        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<i;
    }
	return 0;
}

