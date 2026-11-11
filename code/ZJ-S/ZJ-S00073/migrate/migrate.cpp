#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		vector <long long> x(n+1);
		for(long long i=1;i<=n;i++) cin>>x[i];
		vector <long long> t(n+2,0);
		long long r=1;
		for(long long i=1;i<=n;i++)
		{
			if(r<i) r=i;
			while(r+1<=n&&abs(x[r+1]-x[i])<=d) r++;
			t[i]=r;
		}
		vector <long long> s(n+2,0);
		for(long long i=1;i<n;i++)
		{
			if(t[i]==t[i+1]) s[t[i]]=1;
		}
		vector <int> vs(n+2,1);
		for(long long i=1;i<=n;i++) if(s[i]) vs[i]=0;
		for(long long i=n;i>=1;i--) if(!s[i]) vs[t[i]]+=vs[i];
		long long ans=0;
		for(long long rr=2;rr<=n;rr++)
		{
			if(s[rr]) 
			{
				continue;
			}
			long long cnt=vs[rr]-1;
			if(cnt<=0) 
			{
				continue;
			}
			long long lb=max(rr,t[rr-2]);
			long long rb=t[rr-1];
			if(rb>lb) ans+=cnt*(rb-lb);
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
