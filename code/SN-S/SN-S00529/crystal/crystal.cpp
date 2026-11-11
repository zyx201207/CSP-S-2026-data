//万育锡 SN-S00529 陕西省西安中学 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin >>n>>m;
	
	vector<ll>a(n+1);
		vector<ll>pre(n+1);
		
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	a[0]=-1LL<<62;
sort(a.begin(),a.end());
	if(n<10000)
	{


	int res=0;
	for(int i=1;i<n;i++)
	{
		pre[i]=a[i+1]-a[i];
//		cout<<"pre"<<i<<"="<<pre[i]<<"\n";
	}
	
	
	
	for(int i=n;i>=1;i--)
	{
		int ans=1;
		ll p=0;
		ll k=0;
		int j=1;
		if(i!=1)
		{
			while(i-j>0)
			{
				if(p+k+pre[i-j]<=m)
				{
					ans++;
					k+=pre[i-j];
					p+=k;
//					cout <<p<<" "<<pre[i-j]<<" "<<"ans="<<ans<<" "<<(p+pre[i-j]<=m)<<"\n";
				}
				else
				{
					break;
				}
				j++;
			}
			
		}
		
		if(ans>=res)
		{
			res=ans;
		}
		
	}
	cout <<res;
	}
	else {
		ll hyw=a[2]-a[1];
		ll ywh=hyw;
		ll genshin=0;
		ll ppp=1;
		while(genshin+ywh<=m)
		{
			
			genshin+=ywh;
			ppp++;
			ywh+=hyw;
			
		}
		
		cout <<ppp;
}

	return 0;
}
