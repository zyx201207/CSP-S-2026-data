#include<bits/stdc++.h>
using namespace std;
struct Jh
{
	int l,r;
};
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q,a,ans;
	cin>>c>>n>>m>>d>>q;
	int w[m+2];
	for(int i=1;i<=m;i++) cin>>w[i];
	int xian[n+2][2];
	Jh jh[q+2];
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=1;j<=2*a;j+=2)
		{
			cin>>xian[i][j]>>xian[i][j+1];
			ans+=max(xian[i][j],xian[i][j+1]);
		} 
	}
	for(int i=1;i<=q;i++) cin>>jh[i].l>>jh[i].r;
	cout<<ans;
	return 0;
}
