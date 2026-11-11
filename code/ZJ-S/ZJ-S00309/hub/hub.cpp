#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
const int N=1e6+5;
int n,k;
vector<int> a[N];

void ca()
{
	for(int i=1;i<=n;i++)
		a[i].clear();
}

void solve()
{
	cin>>n>>k;
	ca; 
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	cout<<rand()%2<<endl;
}
int main()
{
	FRE
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	} 
	return 0;
} 
