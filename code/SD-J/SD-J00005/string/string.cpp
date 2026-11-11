#include<iostream>
using namespace std;
struct node 
{
	int cnt;
	char c;
}a[200005];
bool check(int i,int j,int ish,int jsh,long long lef,long long mid)
{
	if(i<j)return 1;
	if(i==j)
	{
		return 1ll*(lef+ish+jsh)*2<=mid;
	}
	if(i>j)return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	long long mid=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cnt>>a[i].c;
		mid+=a[i].cnt;
	}
	int i=1,j=n;
	long long ans=0;
	int ish=0,jsh=0;
	long long lef=0;
	while(lef*2<mid&&check(i,j,ish,jsh,lef,mid))
	{
		if(i==j)
		{
			
			break;	
		}
		if(ish==jsh&&ish==0)
		{
			if(a[i].cnt>a[j].cnt)
			{
				if(a[i].c!=a[j].c)
				{
					ans+=a[j].cnt;
				}
				ish=a[i].cnt-a[j].cnt;
				lef+=a[j].cnt;
				j--;
			}
			else if(a[i].cnt<a[j].cnt)
			{
				if(a[i].c!=a[j].c)
				{
					ans+=a[i].cnt;
				}
				jsh=a[j].cnt-a[i].cnt;
				lef+=a[i].cnt;
				i++;
			}
			else
			{
				if(a[i].c!=a[j].c)
				{
					ans+=a[i].cnt;
				}
				lef+=a[i].cnt;
				i++,j--;
			}
			
		}
		else if(ish!=0)
		{
			//比较左边剩的和右边整块的
			if(ish>a[j].cnt)
			{
				if(a[i].c!=a[j].c)
				{
					ans+=a[j].cnt;
				}
				ish-=a[j].cnt;
				lef+=a[j].cnt;
				j--;
			 } 
			 else if(ish<a[j].cnt)
			 {
			 	if(a[i].c!=a[j].c)
			 	{
			 		ans+=ish;
				 }
				 jsh=a[j].cnt-ish;
				 ish=0;
				 i++;
			 }
			 else 
			 {
			 	if(a[i].c!=a[j].c)
			 	{
			 		ans+=ish;
				 }
				 ish=0;
				 lef+=a[j].cnt;
				 i++,j--;
			 }
		}
		else if(jsh!=0)
		{
			if(jsh>a[i].cnt)
			{
				if(a[i].c!=a[j].c)
				{
					ans+=a[i].cnt;
				}
				jsh-=a[i].cnt;
				lef+=a[i].cnt;
				i++;
			}
			else if(jsh<a[i].cnt)
			{
				if(a[i].c!=a[j].c)
				{
					ans+=jsh;
				}
				ish=a[i].cnt-jsh;
				jsh=0;
				j--;
			}
			else
			{
				if(a[i].c!=a[j].c)
				{
					ans+=jsh;
				}
				jsh=0;
				lef+=a[i].cnt;
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
