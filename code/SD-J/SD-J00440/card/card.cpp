#include<bits/stdc++.h>
using namespace std;
int a[500010];
int had[500010];
int n,m;
void game(int round)
{
	vector<int>desk;
	for(int i=round-1;i<n;i++)
	{
		desk.push_back(a[i]);
	}
	for(int i=0;i<=(n-round);i++)
	{
		had[desk[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		game(i);
	}
	for(int i=0;i<m;i++)
	{
		cout<<had[i]+1<<' ';
	}
	return 0;
}

//没时间遂放弃，希望有分 
