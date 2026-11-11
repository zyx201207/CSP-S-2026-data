#include<bits/stdc++.h>
using namespace std;
const LL long long
LL n,m,a[200010],b[200010],maxn=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	b[1]=a[1]&a[2];
	for(int i=2;i<=n;i++) 
	    b[i]=b[i-1]&a[i+1];
	for(int i=m+1;i<=n;i++)
		maxn=max(maxn,b[i]&b[i-1]);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
