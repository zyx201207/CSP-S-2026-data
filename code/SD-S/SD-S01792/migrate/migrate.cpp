#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000006];
ll c,t,n,d,cnt,ans,tep;
pair<ll,ll>s[2000006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++) s[i].first=0,s[i].second=0;
			s[k].first=1,s[k].second=1;
			for(int i=k+1;i<=n;i++)
			{
				cnt=0x3f3f3f3f,tep=1;
				while(a[i]-a[i-tep]<=d&&i-tep>=k){cnt=min(cnt,s[i-tep].second);tep++;}
				s[i].second=cnt+1;
				for(int j=1;j<tep;j++)if(s[i-j].second==cnt) {s[i].first+=s[i-j].first;}
				if(s[i].first==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
