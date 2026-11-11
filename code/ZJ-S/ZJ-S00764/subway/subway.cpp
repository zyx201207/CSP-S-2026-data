#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[100000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i)
	    cin>>w[i];
	ll map[100000][2];
	vector<ll> graph[100000];
	ll idx=0;
	while(n--)
	{
		ll stage;
	 	cin>>stage;
	 	while(stage--)
	 	{
		    ll pass,time;
		    cin>>pass>>time;
		    map[++idx][0]=pass;
		    map[idx][1]=time;
		    graph[idx].push_back(pass);
		}
	}
	while(q--)
	{
		ll st,ed;
		cin>>st>>ed;
        bool single_way=false;
        ll way;
		for(ll i=1;i<=idx;++i)
		{
			bool st1=false,ed1=false;
			for(std::vector<ll>::iterator it=graph[i].begin();it!=graph[i].end();++it)
			{
				if(*it==st)
				   st1=true;
				if(*it==ed1)
				   ed1=true;
			}
			if(st1&&ed1)
			{
			   single_way=true;  
			   way=i;
		    }	 
		}
		ll ans=0;
		if(single_way)
		{
			ans+=w[st];
			ans+=w[ed];
			for(ll i)
			{
				pair<ll,ll> pa=*it;
				if(pa.first()==st)
				    ans+=pa.second();
				else if(pa.first()==ed)
				    ans+=pa.second();
			}
		}
		cout<<ans;
		continue;	
	}
}
