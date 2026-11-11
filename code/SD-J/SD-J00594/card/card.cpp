#include<nits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	for(int i=1;i<=n;i++)
		if(ans!=a[i]) f=0;
	if(f) cout<<1;
	else cout<<2;
	return 0;	
} 
