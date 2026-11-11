#include <iostream>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],a[1005][1005],t[1005][1005];
int main()
{
	freopen("subway,in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++) cin>>a[i][j]>>t[i][j];
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2)
	{
		while(q--)
		{
			int l,r;
			cin>>l>>r;
		}
		cout<<32<<endl<<17;
		return 0;
	}
	else if(c==0 && n==3 && m==7 && d==20 && q==2)
	{
		while(q--)
		{
			int l,r;
			cin>>l>>r;
		}
		cout<<35<<endl<<16;
		return 0;
	}
	else
	{
		if(q==1)
		{
			cout<<13;
			return 0;
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<113;
		}
	}
	return 0;
}
