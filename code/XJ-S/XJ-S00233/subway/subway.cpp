#include<bits/stdc++.h>
using namespace std;
int c,n,m,l,r,q,p,a[5000010],k,b[1000010],sum;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>p>>q;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int i=1;i<=n;i++){
		cin>>b[i];
		sum+=b[i];
	}
	}
	while (q--)
	{
		cin>>l>>r;
		cout<<sum/l; 
	}
	return 0; 
}
