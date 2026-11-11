#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[500001],x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n/m==1)cout<<m<<' '<<a[0]<<' '<<a[n-1]+a[n-2];
	else cout<<n<<' '<<a[0]<<' '<<a[n-1]+a[n-2];
	return 0;
}
