#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
ll a[500005],x[500005];
map<ll,ll>mp;
vector<ll> v;
struct node
{
    ll x,y;
    friend bool operator<(node a,node b)
    {
        if(a.x!=b.x)
        {
            return a.x>b.x;
        }
        return a.y<b.y;
    }
};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
    cin>>n>>m;
    ll mxx=0,zz;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]==1)
        {
            v.push_back(a[i]);
        }
        if(mxx<mp[a[i]])
        {
            mxx=mp[a[i]];
            zz=a[i];
        }
    }
    sort(v.begin(),v.end());
    ll l=v.size();
    priority_queue<node> q,q1;
    for(ll i=0;i<l;i++)
    {
        if(v[i]!=zz)
        {
            if(v[i]>=zz)
            {
                q.push({(v[i]-zz),mp[v[i]]});
            }
            else
            {
                q1.push({(zz-v[i]),mp[v[i]]});
            }
        }
    }
    ll k=0;
    ll flag=0;
    while(m)
    {
    	if(q.empty())
    	{
    		flag=1;
    		break;
		}
		if(q1.empty())
    	{
    		flag=2;
    		break;
		}
        node x=q.top();
        node x1=q1.top();
        if((x.x+k)<=(x1.x-k))
        {
        	ll g_x=m/(x.x+k);
            mp[zz]+=min(x.y,g_x);
            m-=x.y*(x.x+k);
            m=max(0LL,m);
            q.pop();
        }
        else
        {
            ll g_x=m/(x1.x-k);
            m-=mp[zz]*(x1.x-k);
            mp[zz]+=min(x1.y,g_x);
            m=max(0ll,m);
            k+=(x1.x-k);
            q1.pop();
        }
    }
    if(flag==1)
    {
    	while(m)
	    {
	        node x1=q1.top();
	        ll g_x=m/(x1.x-k);
            m-=mp[zz]*(x1.x-k);
	        mp[zz]+=min(x1.y,g_x);
	        m=max(0LL,m);
            k+=(x1.x-k);
	        q1.pop();
	    }
	}
	if(flag==2)
	{
		while(m)
	    {
	        node x=q.top();
	        ll g_x=m/(x.x+k);
	        mp[zz]+=min(x.y,g_x)+k;
	        m-=x.y*(x.x+k);
	        m=max(0LL,m);
	        q.pop();
	    }
	}
    cout<<mp[zz];
	return 0;
}