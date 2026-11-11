#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,l,cl=1;
char c1;
long long L,ans;
struct Node
{
	int num,cha;
}a[maxn];
struct node1
{
	int num,cha;
}b[maxn];
struct node2
{
	int num,cha;
}c[maxn];
struct node3
{
	int num,cha;
}d[maxn];
bool flag=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>c1;
		a[i].cha=c1-'a'+1;
		L+=a[i].num;
	}
	long long sum=0;
	int tmp1=0,tmp2=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i].num;
		if(flag)
		{
			b[++tmp1].num=a[i].num,b[tmp1].cha=a[i].cha;
		}
		else
			c[++tmp2].num=a[i].num,c[tmp2].cha=a[i].cha;
		if(sum==L/2&&flag)
		{
			flag=false;
		}
		if(sum>L/2&&flag)
		{
			b[tmp1].num-=sum-L/2;
			c[++tmp2].num=sum-L/2;
			c[tmp2].cha=a[i].cha;
			flag=false;
		}
	}
	if(L%2!=0)
	{
		c[cl].num--;
		if(c[cl].num==0)
			cl++;
	}
	for(int i=cl;i<=tmp2;i++)
	{
		d[i].num=c[tmp2+cl-i].num;
		d[i].cha=c[tmp2+cl-i].cha;
	}
	for(int i=1;i<=tmp1;i++)
	{
		if(b[i].num>d[cl].num)
		{
			while(b[i].num>d[cl].num)
			{
				if(b[i].num<=d[cl].num)
					break;
				if(b[i].cha==d[cl].cha)
				{
					b[i].num-=d[cl].num;
					cl++;
				}
				else
				{
					ans+=d[cl].num;
					b[i].num-=d[cl].num;
					cl++;
				}
			}
		}
		if(b[i].num<d[cl].num)
		{
			if(b[i].cha==d[cl].cha)
				d[cl].num-=b[i].num;
			else
			{
				ans+=b[i].num;
				d[cl].num-=b[i].num;
			}
			continue;
		}
		if(b[i].num==d[cl].num)
		{
			if(b[i].cha==d[cl].cha)
				cl++;
			else
			{
				ans+=b[i].num;
				cl++;
			}
			continue;
		}
	}
	cout<<ans;
	return 0;
}