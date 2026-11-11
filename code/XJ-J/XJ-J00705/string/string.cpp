#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
struct node{
	int a;
	char c; 
}p[N];
long long int ans;
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(p[l].a!=p[r].a&&p[l].c==p[r].c)
		{
			if(p[l].a>p[r].a)
			{
				p[l].a-=p[r].a;
				r--;
			}
			else if(p[l].a<p[r].a)
			{
				p[r].a-=p[l].a;
				l++;
			}
			else if(p[l].a==p[r].a)
			{
				l++;
				r--;
			}
		}
		else if(p[l].c!=p[r].c)//2a 2b 1c 
		{
			if(p[l].a>p[r].a)
			{
				p[l].a-=p[r].a;
				ans+=p[r].a;
				r--;
			}
			else if(p[l].a<p[r].a)
			{
				p[r].a-=p[l].a;
				ans+=p[l].a;
				l++;
			}
			else if(p[l].a==p[r].a)
			{
				ans+=p[r].a;
				l++;
				r--;
			}
		}
	}
	// 2a 2b 1c
	// a!=c
	// ans+=1
	// 2a-a =a
	// a!=b
	cout<<ans;
}