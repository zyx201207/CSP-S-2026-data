#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int t=1;
const int N=5e5+50;
const int M=3e5+50;
int n,m,a[N];
stack<int> lst[M]; 
stack<int> stk;
ll res[M],lft[M];
bool instk[M];
priority_queue<int>mx,del;
void Out(int color)
{
	del.push(lst[color].top());
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		lst[i].push(0);
		lft[i]=n+1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lst[a[i]].push(i);
	}
	mx.push(0);
	for(int i=n;i>0;i--)
	{
		lst[a[i]].pop();del.push(i);
		if(instk[a[i]])//出现过的卡仅供消耗右端使用 
		{
			while(a[stk.top()]!=a[i])
			{
				instk[a[stk.top()]]=0;
				Out(a[stk.top()]);stk.pop();
			}
			continue;
		}
		
		while(del.size()&&mx.top()==del.top())
		{
			mx.pop();del.pop();
		}
		res[a[i]]+=max(0ll,min(1ll*i,lft[a[i]])-mx.top());
		lft[a[i]]=min(lft[a[i]],1ll*mx.top());
		
		stk.push(i);
		instk[a[i]]=1;
		mx.push(lst[a[i]].top()); 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<res[i]<<' ';
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

