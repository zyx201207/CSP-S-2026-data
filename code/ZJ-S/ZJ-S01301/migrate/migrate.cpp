#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const ll inf=5e18;
int c,T;
int n;
ll d;
vector<pair<int,int>> Ans;
inline ll solve(vector<ll> &x,bool back=0)
{
	vector<int> L(n+1),R(n+1); // 向左跳 和 向右跳 分别最远能跳到哪
	for(int i=1;i<=n;i++) L[i]=R[i]=i;
	queue<int> q;
	x[n+1]=inf;
	for(int i=1;i<=n+1;i++)
	{
		while(!q.empty()&&x[i]-x[q.front()]>d) R[q.front()]=i-1,q.pop();
		q.push(i);
	}
	queue<int>().swap(q);
	x[0]=-inf;
	for(int i=n;i>=0;i--)
	{
		while(!q.empty()&&x[q.front()]-x[i]>d) L[q.front()]=i+1,q.pop();
		q.push(i);
	}
	vector<pair<int,int>> s;
	int pos=1;
	ll ans=0;
	for(int lll=1;lll<=n;lll++)
	for(int rr=lll+1;rr<=n;rr++)
	{
		int pos=lll;
		s.clear();
		while(min(rr,R[pos])!=pos)
		{
			int nxt=min(R[pos],rr); // 跳到最远能够跳到的地方
			if(L[nxt]==pos-1) s.push_back({pos,nxt}); // posl & posr
			pos=nxt;
		}
		if(pos!=rr) continue;
		ans+=s.size()==1;
	}
	s.push_back({n+1,n+1});
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		Ans.clear();
		ll ans=0;
		cin>>n>>d;
		vector<ll> x(n+2);
		for(int i=1;i<=n;i++) cin>>x[i];
		ans+=solve(x);
		cout<<Ans.size()<<'\n';
	}
	return 0;
}
// bx BreakPlus