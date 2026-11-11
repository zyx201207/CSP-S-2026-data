#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;
ll c,t,n,d,g[N],s[N],ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>g[i];
		ll a=1,b=2;
		while(a<=n)
		{
			if(g[b]-g[a]<=d)
			{
				s[a]=max(s[a],b);
				if(b!=n) b++;
				else a++;
			}
			else s[a]=max(s[a],a),a++,b--;
		}
		ans=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]-i==2&&s[i+1]-i-1==2) ans++;
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}