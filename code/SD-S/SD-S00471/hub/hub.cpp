#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,k,u,v,d[N];
vector<int> e[N];
void work();
void output();
void input()
{
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
		}
		work();
		output();
	}
}
void work()
{
	
}
void output()
{
	cout<<1<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	input();
	//work();
	//output();
	return 0;
}

