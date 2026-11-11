#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans,d;
bool q[N];
bool task1=1,task2=1;
int merge(int l,int r)
{
	return a[r]*(r-l)-(s[r-1]-s[l-1]);
}

int check(int mid)
{
	int sum=0,cnt=0;
	if(task2)
	{
		if(n%2==0)
		{
			for(int i=2;i<=n;i+=2)
			{
				if(sum+d<=m)
				{
					sum+=d;
					cnt+=2;
				}
				else break;
			}
			return (cnt>=mid);
		}
		else
		{
			for(int i=2;i<=n-3;i+=2)
			{	
				if(sum+d<=m)
				{
					sum+=d;
					cnt+=2;
				}
				else break;
			}
			if(sum+3*d<=m)
			{
				sum+=3*d;
				cnt+=3;
			}
			else if(sum+d<=m)
			{
				sum+=d;
				cnt+=2;
			}
			return (cnt>=mid);
		}
	
	}
	else
	{
		for(int l=1;l+mid-1<=n;l++)
		{
			int r=l+mid-1;
			if(merge(l,r)<=m)
			{
				return 1;
			}
		}
	}
	
	return 0;
}

struct Node
{
	int l,r,w;
};

bool cmp(Node s1,Node s2)
{
	if(s1.w==s2.w) return s1.l<s2.l;
	return s1.w<s2.w;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	d=a[2]-a[1];
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			task1=0;
			break;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d)
		{
			task2=0;
			break;
		}
	}
	sort(a+1,a+1+n);
	
	if(task1)
	{
		if(n%2==0)
		{
			if(m>=n/2) cout<<n;
			else cout<<m*2;
		}
		else
		{
			if(m<=n/2) cout<<m*2;
			else if(m>n/2)
			{
				if(m>=n/2+2) cout<<n;
				else cout<<n-1;
			}
		}
		return 0;
	}
//	7
//	3
//	2 4 6 8 10 12 14

	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//3
//6
//2 4 6

//6
//10000
//1 2 3 4 5 6

//7
//7
//2 4 6 8 10 12 14
//9
//6
//1 2 3 4 5 6 7 8 9

//5 5
//1 2 4 8 9

//5 8
//-3 -1 2 2 7