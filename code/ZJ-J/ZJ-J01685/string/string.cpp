#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout)
using namespace std;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<ll,char>;
const int N=2e5+5;
int n;
ll ans;
deque<PI> dq;
int main()
{
	fr(string);
	fw(string);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		char y;
		cin>>x>>y;
		dq.pb({x,y}); 
	}
	while(sz(dq)>1)
	{
		if(dq.front().se!=dq.back().se)
		{
			if(dq.front().fi>dq.back().fi)
			{
				dq.front().fi-=dq.back().fi;
				ans+=dq.back().fi;
				dq.pop_back();
			}
			else if(dq.front().fi==dq.back().fi)
			{
				ans+=dq.back().fi;
				dq.pop_front(); 
				dq.pop_back();
			}
			else
			{
				dq.back().fi-=dq.front().fi;
				ans+=dq.front().fi;
				dq.pop_front();
			}
		}
		else
		{
			if(dq.front().fi>dq.back().fi)
			{
				dq.front().fi-=dq.back().fi;
				dq.pop_back();
			}
			else if(dq.front().fi==dq.back().fi)
			{
				dq.pop_front(); 
				dq.pop_back();
			}
			else
			{
				dq.back().fi-=dq.front().fi;
				dq.pop_front();
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
