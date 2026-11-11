#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    long long w[200000];
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	long long a[200000],t[200000];
	for(int i=1;i<=n;i++)
    {
	    cin>>k;
		cin>>a[i]>>t[i];
	}
    return 0;
}
