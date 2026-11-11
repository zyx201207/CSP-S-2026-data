#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],mx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1) cout<<mx;
	else 
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
