#include<iostream>//T4 思路：手工栈1 
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6;
const int M=3e5+10;
int zhan[N],a[N],cnt[M],n,m;
int top;//栈顶;
void add(int x)
{
	top++;
	zhan[top]=x;
}
void pop(int len)
{
	top-=len;
}
int find(int key)
{
	for(int i=top;i>=1;--i)
	{
		if(zhan[i]==key)return i;
	}
	return 0;
}
int find_fast(int key)
{
	int l=1,r=top;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		else if(key<a[mid])r=mid-1;
		else l=mid+1;
	}
	return -1;
}
void ans(int c)
{
	for(int i=c;i<=n;i++)
	{
		if(top<=0)add(a[i]);
		else
		{
			int tem=find(a[i]);
			if(tem==0)add(a[i]);
			else
			{
				pop(top-tem+1);
				add(a[i]);
			} 
		}
	}
	sort(zhan+1,zhan+top+1);
	for(int i=1;i<=m;i++)
	{
		if(find_fast(i)!=-1)cnt[i]++;
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans(i);
		top=0;
	}
	for(int i=1;i<=m;++i)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

