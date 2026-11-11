#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+5;
int ID,t;
int n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<(n-k)/2<<'\n';
	}
	return 0;
}
/*
12251 99999
*/

