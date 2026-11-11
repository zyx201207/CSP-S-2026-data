#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int len;
vector<pair<int,char>> v1;
vector<pair<int,char>> v2;
int id,l1,l2;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int cnt=0;
	//找到中间点
	for(int i=1;i<=n;i++)
	{
		if(cnt+a[i]<(len+1)/2)
		{
			cnt+=a[i];
		}
		else
		{
			id=i;
			if(len%2==0)
			{
				l1=len/2-cnt;
				l2=a[i]-l1;
			}
			else
			{
				l1=max(0ll,(len+1)/2-cnt-1);
				l2=max(0ll,a[i]-l1-1);
			}
			break;
		}
	}
	//找左边的 
	if(l1)
	{
		v1.push_back({l1,c[id]});
	}
	for(int i=id-1;i>=1;i--)
	{
		v1.push_back({a[i],c[i]});
	}
	//找右边的 
	if(l2)
	{
		v2.push_back({l2,c[id]});
	}
	for(int i=id+1;i<=n;i++)
	{
		v2.push_back({a[i],c[i]});
	}
	int pos1=0,pos2=0;
	int ans=0;
	while(pos1<(int)v1.size())
	{
		if(v2[pos2].first<=v1[pos1].first)
		{
			v1[pos1].first-=v2[pos2].first;
			ans+=(v2[pos2].first)*(v1[pos1].second!=v2[pos2].second);
			pos2++;
		}
		else
		{
			ans+=(v1[pos1].first)*(v1[pos1].second!=v2[pos2].second);
			v2[pos2].first-=v1[pos1].first;
			pos1++;
		}
	}
	cout<<ans;
	return 0;
}
