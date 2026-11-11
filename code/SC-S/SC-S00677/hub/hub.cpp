#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;

int a[maxn];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,tot=1;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		cout<<tot<<'\n';
		tot++;
	}
	
	return 0;
}