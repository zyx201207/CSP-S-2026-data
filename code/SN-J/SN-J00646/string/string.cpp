//吕思齐  西安翱翔中学  SN-J00646
#include <bits/stdc++.h>
using namespace std;
struct dat{
	int ai;
	char ci;
} a[200200];
int n;
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) cin>>a[i].ai>>a[i].ci;
	int anow = 1,bnow = 1,st = 0;
	char x;
	bool p = 0;//0 A ; 1 B
	while(anow <= n && bnow <= n)
	{
		if(st == 0)
		{
			if(a[anow].ci == a[n+1-bnow].ci) 
			{
				if(a[anow].ai > a[n+1-bnow].ai)
				{
					st = a[anow].ai - a[n+1-bnow].ai;
					x = a[anow].ci;
					bnow++;
					p = 0;
				}
				else if(a[anow].ai == a[n+1-bnow].ai)
				{
					anow++;
					bnow++;
				}
				else if(a[anow].ai < a[n+1-bnow].ai)
				{
					st = a[n+1-bnow].ai - a[anow].ai;
					x = a[n+1-bnow].ci;
					anow++;
					p = 1;
				}
			}
			else 
			{
				if(a[anow].ai > a[n+1-bnow].ai)
				{
					cnt += a[n+1-bnow].ai;
					st = a[anow].ai - a[n+1-bnow].ai;
					x = a[anow].ci;
					bnow++;
					p = 0;
				}
				else if(a[anow].ai == a[n+1-bnow].ai) 
				{
					cnt+= a[anow].ai;
					anow++;
					bnow++;
				}
				else if(a[anow].ai < a[n+1-bnow].ai)
				{
					cnt += a[anow].ai;
					st = a[n+1-bnow].ai - a[anow].ai;
					x = a[n+1-bnow].ci;
					anow++;
					p = 1;
				}
			}
		}
		else
		{
			if(p == 0)//A多 
			{
				if(x == a[n+1-bnow].ci) //字符相等 
				{
					if(st > a[n+1-bnow].ai)//多余的大 
					{
						st = st - a[n+1-bnow].ai;
						bnow++;
						p = 0;
					}
					else if(st == a[n+1-bnow].ai)
					{
						st = 0;
						anow++;
						bnow++;
					}
					else if(st < a[n+1-bnow].ai)//多余的小 
					{
						st = a[n+1-bnow].ai - st;
						x = a[n+1-bnow].ci;
						anow++;
						p = 1;
					}
				}
				else//字符不相等 
				{
					if(st > a[n+1-bnow].ai)//大 
					{
						cnt += a[n+1-bnow].ai;
						st = st - a[n+1-bnow].ai;
						bnow++;
						p = 0;
					}
					else if(st == a[n+1-bnow].ai)
					{
						cnt += st;
						st = 0;
						anow++;
						bnow++;
					}
					else if(st < a[n+1-bnow].ai)//小 
					{
						cnt += st;
						st = a[n+1-bnow].ai - st;
						x = a[n+1-bnow].ci;
						anow++;
						p = 1;
					}
				}
			}
			else//B多 
			{
				if(x == a[anow].ci) 
				{
					if(st > a[anow].ai)
					{
						st = st - a[anow].ai;
						anow++;
						p = 1;
					}
					else if(st == a[anow].ai) 
					{
						st = 0;
						anow++;
						bnow++;
					}
					else if(st < a[anow].ai)
					{
						st = a[anow].ai - st;
						x = a[anow].ci;
						bnow++;
						p = 0;
					}
				}
				else
				{
					if(st > a[anow].ai)
					{
						st = st - a[anow].ai;
						cnt += a[anow].ai;
						anow++;
						p = 1;
					}
					else if(st == a[anow].ai) 
					{
						cnt += st;
						st = 0;
						anow++;
						bnow++;
					}
					else if(st < a[anow].ai)
					{
						cnt += st;
						st = a[anow].ai - st;
						x = a[anow].ci;
						bnow++;
						p = 0;
					}
				}
			}
		}
	}
	cnt = (cnt+1)/2;
	printf("%lld\n",cnt);
	return 0;
 } 
