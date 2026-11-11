#include<bits/stdc++.h>
#define ll long long
#define pair pair<int,int>
using namespace std;
int c,T;
int n,k;
vector<pair>a;
void solve1()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		a.push_back({u,v});
	}
	sort(a.begin(),a.end());
	unique(a.begin(),a.end());
	
	return ;
}
void solve2()
{
	
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		if(c<=10)solve1();
		else solve2();
	}
	return 0;
}
/*
*/

