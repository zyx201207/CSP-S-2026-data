#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],lst[300005];
int c[500005];
vector<int> t[300005];
pair<int,int> q2[500005];
int cnt1,cnt2,ans[300005];
bool flag[500005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	while(x<=n)
	{
		c[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int s=0;
	while(x)
	{
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]].push_back(i);
	}
	for(int k=1;k<=n;k++)
	{
		cnt2=0;
		for(int j=1;j<=m;j++) lst[j]=0,flag[j]=false;
		for(int j=k;j<=n;j++) 
		{
			if(lst[a[j]]!=0) 
			{
				q2[++cnt2]={lst[a[j]]+1,j+1};
				lst[a[j]]=0;
			}
			lst[a[j]]=j;			
		}
		for(int i=0;i<=n;i++) c[i]=0;
		
		q2[++cnt2]={1,k};
		sort(q2+1,q2+cnt2+1,cmp);
		for(int j=1;j<=cnt2;j++)
		{
			if(q2[j].first>q2[j].second||query(q2[j].first)!=0||query(q2[j].second)!=0) continue;
			add(q2[j].first,1);
			add(q2[j].second,-1);
		}
		for(int j=1;j<=n;j++)
		{
			if(query(j)==0&&!flag[a[j]])
			{
				flag[a[j]]=true;
				ans[a[j]]++;
			} 
		}		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}