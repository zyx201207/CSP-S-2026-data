#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
ll n,m,a[N],ans,cnt=1;
bool f=0;

ll ch(ll x,ll y)
{
	ll sum=0;
	for(ll i=x,j=1;i<y;i++) sum+=a[y]-a[i];
	return sum;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]-a[i-1]==a[i-1]-a[i-2]&&i>=2) cnt++;
	}
	if(cnt==n) f=1;
	if(f==0)
	{
		sort(a+1,a+1+n);
		for(ll i=1,j=2;i<=n,j<=n;)
		{
			if(i>=j) continue;
			if(ch(i,j)>m) i++;
			else{j++; ans=max(j-i,ans);}
		}
		cout<<ans;
	}else{
		ll k=a[2]-a[1];
		for(ll i=1,j=0;i<=n;i++)
		{
			j+=i;
			if(j*k>m){cout<<i; break;}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}