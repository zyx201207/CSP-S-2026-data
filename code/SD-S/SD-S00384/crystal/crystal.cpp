#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,m;
int a[500005];
int mi = INT_MAX,ma = INT_MIN;
struct node
{
	int id,v;
}b[500005];
bool cmp(node a,node b)
{
	return a.v<b.v; 
}
int vis[500005];
int bb[500005];
map<int,int> mp;
signed main()
{
	fast;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int i;
	int oo;
	bool fl = 1;
	bool fll = 1;
	bool flll = 1; 
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			flll = 0;
		if(a[i]>=-100&&a[i]<=100)
			;
		else
			fl = 0;
		mi = min(mi,a[i]);
		ma = max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	oo = a[2]-a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=oo)
		{
			fll = 0;
			break;
		}
	}
	int ans = 0,pi = 0,pj = 0;
	if(flll)
	{
		for(i=1;i<=n;i++)
		{
			int c = i-1;
			int p = c*(c+1)/2;
			if(p<=m)
				ans = i;
		}
		cout<<ans<<endl;
	}
	if(fll)
	{
		for(i=1;i<=n;i++)
		{
			int c = (a[i]-a[1])/oo;
			int d = c*(c+1)/2*oo;
			if(d<=m)
				pi = a[i],ans = i;
		}
		cout<<ans<<endl;
//		cout<<pi<<endl<<endl; 
		return 0;
	}
	else if(fl)
	{
		int j;
		for(i=1;i<=n;i++)
			a[i] += 100,vis[a[i]]++,ans = max(ans,vis[i]);
		for(i=a[1];i<=a[n];i++)
		{
			if(clock()>975)
				break;
			int t = i-1;
			int nw = 0;
			int ppp = vis[i];
			while(t>=1&&nw<=m)
			{
				int c = vis[t]*(i-t);
				if(nw+c>m)
				{
					int pp = i-t,cnt = (m-nw)/pp;
					nw += cnt*pp;
					ppp += cnt;
					break;
				}
				nw += c;
				ppp += vis[t];
				t--;
			}

			if(nw<=m)
				ans = max(ans,ppp);
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		int j;
		for(i=1;i<=n;i++)
			bb[i] = a[i];
		int cc = 0;
		for(i=1;i<=n;i++)
		{
			if(!mp[bb[i]])
				a[++cc] = bb[i];
			mp[bb[i]]++;
		}
		int ii;
		for(ii=1;ii<=cc;ii++)
		{
			if(clock()>975)
				break;
			int i = a[ii];
			int i2 = ii-1;
			int t = a[i2];
			int nw = 0;
			int ppp = mp[i];
//			printf("初始%d\n",ppp);
			while(i2>=1&&nw<=m)
			{
				t = a[i2];
				int c = mp[t]*(i-t);
//				printf("从%d吃%d要吃%d\n",i,t,c);
				if(nw+c>m)
				{
					int pp = i-t,cnt = (m-nw)/pp;
					nw += cnt*pp;
					ppp += cnt;
					break;
				}
				nw += c;
				ppp += mp[t];
				i2--;
			}
//			printf("目前:%lld 用了%lld 答案:%lld\n",i,nw,ppp);
//			cout<<ppp<<endl;
			if(nw<=m)
				ans = max(ans,ppp);
		}
		cout<<ans<<endl;	
	}
	return 0;
}


/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7

*/
