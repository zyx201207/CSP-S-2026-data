#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e12;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n;ll m;
	cin>>n>>m;
	ll mx=0;
	vector<ll>a(n,0),b(n+1,0),c(n+1,0),sp(n+1,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[i+1]=a[i];
		a[i]+=N;
		
	}
	sort(c.begin()+1,c.end());
	
sort(a.begin(),a.end());
a.erase(unique(a.begin(),a.end()),a.end());
for(int i=1;i<=n;i++)
{
	b[i]=lower_bound(a.begin(),a.end(),a[i])-a.begin();
	if(mx<b[i])mx=b[i];
}
vector<int>cnt(mx+1,0);
for(int i=1;i<=n;i++)cnt[b[i]]++;
//	for(int i=1;i<=n;i++)cout<<c[i]<<' ';
	
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		sp[i]=c[i]-c[i-1];
	}
	sp[1]=0;
	ll ss=sp[2];
	for(int i=2;i<=n;i++)
	{
		if(b[i]!=b[i-1])
		{//if(cnt[b[i-1]]>1)cnt[b[i-1]]--;
			ss=sp[i]*cnt[b[i-1]]+sp[i-1];
		
			cnt[b[i]]+=cnt[b[i-1]] ;
		}
			else 
			{
				sp[i]=ss;
			}
			//cout<<ss<<'\n';
			if(ss>m)
			{
				ans=i-1;break;
			}
		
	}
	cout<<ans<<'\n';
 } 
