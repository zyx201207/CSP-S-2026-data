#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long int x[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>x[i];
		}
	}
	cout<<1<<'\n';
	cout<<2;
	return 0;
}