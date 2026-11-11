#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,t;
ll n,d,a[N],ans,cnt,mi=2e6+10;
void dfs(ll lf,ll rg,ll s){
	if(lf==rg){
		if(s<mi)
		{
			mi=s;
			cnt=0;
		}
		cnt++;
	}
	for(int i=lf+1;i<=rg;i++)
	{
		if(a[i]-a[lf]<=d)dfs(i,rg,s+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(ll i=1;i<n;i++)
		{
			ll j=i+1;
			while(j<=n&&a[j]-a[i]<=d)
			{
				j++;
			}
			if(j>n)break;
			for(j;j<=n;j++)
			{
				ll r=j;
				dfs(i,r,0);
				if(cnt==2)ans++;
				cnt=0;
				mi=2e6+10;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

