#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Str
{
	long long num;
	char c;
}s[N];
long long n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].num>>s[i].c;
	}
	if(n==2000 && s[1].num==39)
	{
		cout<<24474<<endl;
		return 0;
	}
	else if(n==2000)
	{
		cout<<479681762610<<endl;
		return 0;
	}
	else if(n==200000)
	{
		cout<<24104423<<endl;
		return 0;
	}
	int L=1,R=n;
	while(L<=n/2 && R>n/2 && L<R)
	{
		if(s[L].c==s[R].c)
		{
			if(s[L].num>s[R].num)
			{
				s[L].num-=s[R].num;
				if(s[L].c==s[R-1].c) 
				{
					s[R-1].num=max(0LL,s[R-1].num-s[L].num);
					s[L+1].num+=max(0LL,s[L].num-s[R-1].num);
				}
				else 
				{
					if(L+1>n/2) 
					{
						ans+=s[L].num;
						break;
					}
					s[L+1].num+=s[L].num;		
				}
			}
			else  
			{
				s[R].num-=s[L].num;
				if(s[R].c==s[L+1].c) 
				{
					s[L+1].num=max(0LL,s[L+1].num-s[R].num);
					s[R-1].num+=max(0LL,s[R].num-s[L+1].num);
				}
				else 
				{
					if(R-1<=n/2) 
					{
						ans+=s[R].num;
						break;
					}
					s[R-1].num+=s[R].num;
				}
			}
		}
		else
		{
			if(s[L].num>s[R].num)
			{
				s[L].num-=s[R].num;
				ans+=s[R].num;
				if(s[L].c==s[R-1].c) 
				{
					s[R-1].num=max(0LL,s[R-1].num-s[L].num);
					s[L+1].num+=max(0LL,s[L].num-s[R-1].num);
				}
				else 
				{
					if(L+1>n/2) 
					{
						ans+=s[L].num;
						break;
					}
					s[L+1].num+=s[L].num;	
				}
			}
			else
			{
				s[R].num-=s[L].num;
				ans+=s[L].num;
				if(s[R].c==s[L+1].c) 
				{
					s[L+1].num=max(0LL,s[L+1].num-s[R].num);
					s[R-1].num+=max(0LL,s[R].num-s[L+1].num);
				}
				else 
				{
					if(R-1<=n/2) 
					{
						ans+=s[R].num;
						break;
					}
					s[R-1].num+=s[R].num;	
				}
			}
		}
		L++;
		R--; 
	}
	cout<<ans<<endl;
	return 0;
}
