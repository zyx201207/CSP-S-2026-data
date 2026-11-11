#include<bits/stdc++.h>
using namespace std;
long long a[600000];
priority_queue<long long,vector<long long>,greater<long long> > q;
priority_queue<long long> p;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0) 
	{
		 long long ans=1;
		for(long long i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]) ans++;
		}cout<<ans;
    return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		 long long cut=0;
		long long ans=0;
		 long long k=i;
		for( long long j=1;j<=k;j++)
		{
			 long long qq;
			qq=a[k]-a[j];
			q.push(qq);
		}
	    while(q.size()!=0)
			{
			long long w=q.top();
			  q.pop();
			  ans+=w;
			  if(ans<=m)
			{
				cut++;
			}
			
		    }
		    p.push(cut);
      }
  long long yyc=p.top();
    cout<<yyc;
	return 0;
}
