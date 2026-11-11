#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],x,t;
vector<pair<int,int> > v[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		while(n--) cin>>x;
		x+=c;
		if(x%3==0) cout<<2;
		else if(x%2==0) cout<<1;
		else cout<<0;
		cout<<endl;
	}
	return 0;
}
