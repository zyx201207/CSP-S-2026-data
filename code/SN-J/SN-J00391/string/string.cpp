#include <bits/stdc++.h>
using namespace std;
char a[1000];
int main()
{
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    {
    	cin>>a[i];
    	if (n==1 && n==m)
	    {
		    cout<<i;
	    }
	}
	return 0;
}
