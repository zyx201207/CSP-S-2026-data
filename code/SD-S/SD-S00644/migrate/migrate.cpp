#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[2000005],step[2000005],dist[2000005],cnt[2000005],ct[2000005];
int c,t,n,d,pl,pr,res;
queue<int> q;

void update(int pos,int val)
{
	cnt[pos]+=val;
	while(pos<=n)
	{
		ct[pos]+=val;
		pos+=(pos&(-pos));
	}
}

int query(int pos)
{
	int sum=0;
	while(pos>=1)
	{
		sum+=ct[pos];
		pos-=(pos&(-pos));
	}
	return sum;
}

bool check1(int st,int ed)
{
	if(dist[st]+1<dist[ed])
	{
		dist[ed]=dist[st]+1;
		update(ed,cnt[st]-cnt[ed]);
		return 1;
	}
	else if(dist[st]+1==dist[ed])
	{
		update(ed,cnt[st]);
		return 1;
	}
	else return 0;
}

bool check2(int st,int ed)
{
	if(dist[st]+1>dist[ed]) return 1;
	else return 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>x[i];
		for(int i=1; i<=n; i++) dist[i]=1e18,cnt[i]=0,ct[i]=0;
		dist[1]=0,update(1,1);
		for(int i=n; i>=1; i--)
		{
			while(!q.empty()&&x[q.front()]-x[i]>d)
			{
				step[q.front()]=q.front()-i-1;
				q.pop();
			}
			q.push(i);
		}
		while(!q.empty()) step[q.front()]=q.front()-1,q.pop();
		
		for(int i=1; i<=n; i++)
		{
			pl=pr=i;
			int l=i-step[i],r=i-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check1(mid,i)) pl=mid,r=mid-1;
				else l=mid+1;
			}
			
			l=pl,r=i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check2(mid,i)) pr=mid,r=mid-1;
				else l=mid+1;
			}
			if(query(pr-1)-query(pl-1)==2) res++;
		}
		
		cout<<res<<"\n";
	}
	
	return 0;
}
