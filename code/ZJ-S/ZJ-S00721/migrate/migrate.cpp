#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l[2000005],n,d,c,t,cha[2000005];
bool p(ll a)
{
	for(ll i=2;i<=d;i++)
	{
		if(a%i==0||a/i!=1)
		return 0;
	}
	return 1;
}
int main()
{
	//freopen("migrate2.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll s=1;s<=t;s++)
	{
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>l[i];
			if(i>=2)
			cha[i]=l[i]-l[i-1];
		}
		for(ll i=1;i<n-1;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(cha[j]>d)
				break;
				ll x=abs(l[j]-l[i]);
				if(p(x))
				ans++;
				if(x>2*d)
				break;
			}
		}
		cout<<ans<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
