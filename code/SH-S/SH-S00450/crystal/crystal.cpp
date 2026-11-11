#include<iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
    int n,m;
    long long a[n];
    cin>>a[n];
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	n+=1;
    	if(n=m)
    	{
    		n+=1;
		}
	}
	cout<<n;
	freopen("crystal.out","w",stdout);
	return 0;
}
