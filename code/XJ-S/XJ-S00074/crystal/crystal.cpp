#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxn=INT_MIN,maxp=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1,0); 
	for(int i=0;i<n;i++)
		cin>>a[i];
	//cout<<endl;
	//for(int num:a) cout<<num;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<n-i+1;j++)
		{
			bool flag=true;
			ll p=a[j+i-1],cnt=0,ans=0;
			for(ll k=j;k<=j+i-1;k++)
			{
				if(cnt>m) 
				{
					flag=false;
					break;
				}
				cnt+=p-a[k];
			}
			if(flag&&(i*p>maxn||i>maxp)) maxp=i,maxn=i*p;
			//cout<<i<<" "<<j<<" "<<p<<' '<<cnt<<" "<<maxn<<endl;
		}
	}
	cout<<maxp;
	return 0;
 } 
