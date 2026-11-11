#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=500005;
ll n;
vector<ll> a(1);
ull m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	ll sum=0;
	for(int i=1; i<=n; i++)
	{
		sum+=a[i];
	}
	double ban=sum/n;
	ll myban=LLONG_MAX;
	for(int i=1; i<=n; i++)
	{
		if(abs(a[i]-ban)<abs(myban-ban))
		{
			myban=a[i];
		}
	}
	sort(a.begin()+1,a.end()+1);

	int idx=0;
	ll sum_ban=0;
	bool f=0;
	short cis=0;
	int cidx=0;
	for(int i=1; i<=n; i++)
	{
		if(a[i]!=myban&&f==1)
		{
			break;
		}
		if(a[i]==myban)
		{
			sum_ban++;
			f=1;
			idx=i;
			cis++;
		}
		if(cis==1)
		{
			cidx=i;
		}
	}
	idx=cidx;
	queue<ll> mymin;
	ll sum2=0;
	for(int i=1; i<idx; i++)
	{
		mymin.push(a[i]);
		sum2+=a[i];
	}
	ll ans=sum_ban;

	for(int i=1; i<idx; i++)
	{
		if((sum2/mymin.size()+m)>=myban)
		{
			ans+=mymin.size();
			break;
		}
		else
		{
			mymin.pop();
			sum2-=a[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
