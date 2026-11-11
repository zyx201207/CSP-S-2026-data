#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[200005];
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
    {
    	sort(a+1,a+n+1);
    	cout<<a[n];
    	return 0;
    }	
    if(m==n)
    {
    	for(int i=2;i<=n;i++)
    	{
    		a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	return 0;
}
