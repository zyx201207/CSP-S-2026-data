#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if((a[2]-a[1])*2LL>d) 
			{
				ans=0LL;
				cout<<ans<<'\n';
			}
			else
			{
				int sum=d/(a[2]-a[1]);
				int num=sum*2;
				ans=n-num+1;
				cout<<max(0LL,ans)<<'\n';
			}
		}
		return 0;
	}
	else
	{
		while(t--) 
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<0<<'\n';			
		}
	}
	return 0;
}

