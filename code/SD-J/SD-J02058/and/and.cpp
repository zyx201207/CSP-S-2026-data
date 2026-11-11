#include <bits/stdc++.h>
using namespace std;
int n,m,a[100002],x,ma,s,b;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		ma=max(x,ma);
		a[x]=1;
	}
	for(int i=ma;s<m;i--)
	{
		if(a[i]==1) s++;
		b=i;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
