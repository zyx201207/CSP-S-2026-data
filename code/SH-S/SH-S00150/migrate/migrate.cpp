#include<bits/stdc++.h>
using namespace std;
#define N 2000006
int n,rng[N];
long long d,x[N];
map<pair<int,int>,int> omp,nmp,tmp;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int l=1,r=1;l<=n;++l)
		{
			while(r<=n&&x[r]-x[l]<=d) ++r;
			rng[l]=r-1;
		}
		for(int i=1;i<=n;++i) nmp[make_pair(i,rng[i])]=1;
		for(int len=2;len<=n;++len)
		{
			for(auto x:nmp)
			{
				int l=x.first.first,r=x.first.second,t=x.second;
				for(int i=1;r-i+1>l;++i)
					if(rng[r-i+1]!=rng[r-i+2]||i==1) tmp[make_pair(l,rng[r-i+1])]+=t*i;
					else tmp[make_pair(l,rng[r-i+1])]+=1;
			}
			for(auto x:nmp) omp[x.first]+=x.second;
			nmp.clear();
			for(auto x:tmp) 
				nmp[x.first]+=x.second;
			tmp.clear();
		}
		for(auto x:omp)
		{
//			cout<<x.first.first<<x.first.second<<x.second<<'\n';
			if(x.second==2) ++ans;
		}
		cout<<ans<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
