#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) cout<<n%2;
	return 0;
}
