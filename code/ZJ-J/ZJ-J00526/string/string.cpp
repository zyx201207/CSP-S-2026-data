#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+200;
struct node
{
	int x;
	char ch;
}a[N];
int n,cnt,num;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		
		if(ch==a[cnt].ch) a[cnt].x+=x;
		else
		{
			a[++cnt].x=x;
			a[cnt].ch=ch;
		}
		num+=x;
	}
	if(num<=588000000)
	{
		string s="";
		
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=a[i].x;j++)
				s=s+a[i].ch;
		cnt=0;
		int l=0,r=s.size()-1;
		while(l<r)
		{
			if(s[l]!=s[r]) cnt++;
			l++,r--;
		}
		cout<<cnt;
		return 0;
	}
	n=cnt;
	cnt=0;
	for(int i=1;i<=(n>>1);i++)
	{
		int j=n-i+1;
		int x1=a[i].x,x2=a[j].x;
		char ch1=a[i].ch,ch2=a[j].ch;
		if(ch1==ch2)
		{
			if(x1<x2)
			{
				a[i].x=x2;
				i++;
				a[i].x=a[i-1].x-(x2-x1);
				i--;
			}
			if(x1>x2)
			{
				a[j].x=x1;
				j--;
				a[j].x=a[j+1].x-abs(x2-x1);
			}
			cnt+=abs(x2-x1);
		}
		else
		{
			if(x1<x2)
			{
				a[i].x=x2;
				i++;
				a[i].x=a[i-1].x-(x2-x1);
				i--;
			}
			if(x1>x2)
			{
				a[j].x=x1;
				j--;
				a[j].x=a[j+1].x-abs(x2-x1);
			}
			cnt+=max(x2,x1);
		}
	}
	cout<<cnt;
	return 0;
}
