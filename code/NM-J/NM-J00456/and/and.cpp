#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000020];
int maxx;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    maxx=a[(n-m)+1];
    for(int j=n;j>=(n-m)+1;j--)
        	maxx=int(a[j]&maxx);
	cout<<maxx;
	return 0;
 } 
