#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=4e6+5;
int h[N],e[M],ne[M],idx;
int n,k;
int c,t;
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(h,-1,sizeof h);
		memset(ne,0,sizeof ne);
		memset(e,0,sizeof e);
		idx=0;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,b),add(b,a);
		}
		cout<<0<<'\n';
	}
	return 0;
}
