#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
	ll x=0,f=1;
	char ch=getchar_unlocked();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar_unlocked();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
	return x*f;
}
struct p
{
	ll id,step;
	bool operator>(const  p t)const{return step>t.step;}
};
struct zh
{
    ll li,ti;
};
vector<p>ve[100009];
priority_queue<p,vector<p>,greater<p>>q;;
ll d[1004][1004],dist[10004],vis[10004];
ll bfs(int st,ll ed)
{
	q.push({st,0});
	while(!q.empty())
	{
		p h=q.top();
		q.pop();
		for(auto&&i:ve[h.id])
		{
			dist[i.id]=min(dist[i.id],dist[h.id]+i.step);
			if(!vis[i.id])q.push({i.id,dist[i.id]});
			vis[i.id]=1;
		}
	}
	return dist[ed];
}
ll w[500001],a[505][2];
vector<zh>k[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ll n,m,q5;
    cin>>n>>n>>m>>q5>>q5;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
		int y;
		cin>>y;
        while(y--)cin>>a[i][0]>>a[i][1];
        k[a[i][0]].push_back({i,a[i][1]});
    }
	for(int i=1;i<=m;i++)
		for(auto&&j:k[i])
			for(auto&&o:k[i])
				ve[j.li].push_back({o.li,o.ti+j.ti}),
				ve[o.li].push_back({j.li,o.ti+j.ti});
    while(q5--)
    {
        memset(dist,1061109567,sizeof dist);
        int st,ed;
        cin>>st>>ed;
		dist[st]=0;
		while(!q.empty())q.pop();
        cout<<bfs(st,ed)+w[st]+w[ed]<<'\n';
    }
	return 0;
}