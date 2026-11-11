#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, m, c, d, q, sum, aum, ans;
int w[N];
int mp[1005][1005] = {0}, id;
struct node
{
	int a;
	int t;
}v[1005][1005];
struct str
{
	int tx, ty;
}p[N];
int op2[100005];
bool fun2(int a, int b)
{
	if(op2[a] == b)
		return 1;
	else
		return 0;
}
void fun(int start, int end)
{
	if(end == start)
	{
		ans = min(ans, aum + mp[0][start]);
		return;
	}
	for(int i = 1; i <= m; i ++)
	{
		if(mp[end][i] != 0)
		{
			if(fun2(i , end))
				aum = aum + mp[end][i] + mp[0][end];
			else
				aum = aum + mp[end][i];
			int um = mp[end][i];
			mp[end][i] = 0;
			fun(start, i);
			mp[end][i] = um;
			aum = aum - mp[end][i] - mp[0][end];
		}
	}
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i ++)
	{
		cin>>w[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin>>sum;
		id = 0;
		for(int k = 1; k <= sum; k ++)
		{
			cin>>v[i][k].a>>v[i][k].t;
			op2[k] = v[i][1].a;
			mp[id][v[i][k].a] = mp[v[i][k].a][id] = v[i][k].t;
			id = v[i][k].a;
		}
	}
	for(int i = 1; i <= q; i ++)
	{
		cin>>p[i].tx>>p[i].ty;
	}
	for(int i = 1; i <= q; i ++)
	{
		int start = p[i].tx;
		int end = p[i].ty;
		ans = 1e9;
		aum = 0;
		fun(start, end);
		ans = ans + w[start] + w[end];
		cout<<ans<<endl;
	}
	return 0;
 } 
