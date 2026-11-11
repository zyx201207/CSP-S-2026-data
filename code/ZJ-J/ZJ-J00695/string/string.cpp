#include<bits/stdc++.h>
using namespace std;
int n;
const int N=200010;
struct node{
	long long a;
	char c;
}x[N];
long long mx=-1;
long long cnt=0;
void solve1()
{
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x[i].a;j++)
		{
			s+=x[i].c;
		}
	}
	int m=s.size(),cnt=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]!=s[m-i-1])cnt++;
	}
	cnt/=2;
	printf("%d",cnt);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&x[i].a,&x[i].c);
		mx=max(mx,x[i].a);
	}
	if(mx<=50)solve1();
	else
	{
		int l=1,r=n;
		while(l<r)
		{
			if(x[l].a>=x[r].a)
			{
				if(x[l].c!=x[r].c)
				{
					cnt+=x[r].a;
	//				cout<<x[r].a<<"\n";
				}
				x[l].a-=x[r].a;
				r--;
				
			}
			else
			{
				if(x[l].c!=x[r].c)
				{
					cnt+=x[l].a;
	//				cout<<x[l].a<<"\n";
				}
				x[r].a-=x[l].a;
				l++;
				
			}
		}
		printf("%lld",cnt);	
	}
	return 0;
}

