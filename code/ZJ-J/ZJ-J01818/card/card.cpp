#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll n,m,a[N],b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int v=1;v<=n;v++)
	{
		vector<ll>x;
		set<ll>s;
		for(int i=v;i<=n;i++)
		{
			ll k=a[i];
			ll sl=s.size();
			s.insert(k);
			if(s.size()==sl)
			{
				ll l=0;
				for(auto t:x)
				{
					if(t==k) break;
					l++;
				}
				ll xl=x.size();
				s.erase(s.begin(),s.end());
				for(int j=0;j<l;j++) s.insert(x[j]);
				for(int j=1;j<=xl-l;j++) x.pop_back();
			}
			x.push_back(k);
			s.insert(k);
		}
		for(auto t:x) b[t]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
1 2 

*/
