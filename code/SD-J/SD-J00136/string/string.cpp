#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
struct node 
{
	int num,c;
}a[N];
int l,r;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	l=1;
	for(int i=1;i<=n;i++)
	{
		int y;cin>>y;
		char x;cin>>x;
		int m=(x-'a');
		a[++r].c=m,a[r].num=y;
	}
	int ans=0;
	while(r-l>=1)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].num==a[r].num) 
			{
				l++,r--;
				continue;
			}
			else 
			{
				if(a[l].num>a[r].num)
				{
					a[l].num-=a[r].num;
					r--;
					continue;
				}
				else
				{
					a[r].num-=a[l].num;
					l++;
					continue;
				}
			}
		}
		else
		{
			if(a[l].num==a[r].num) 
			{
				ans+=a[l].num;
				l++,r--;
			}
			else 
			{
				if(a[l].num>a[r].num)
				{
					a[l].num-=a[r].num;
					ans+=a[r].num;
					r--;
				}
				else
				{
					a[r].num-=a[l].num;
					ans+=a[l].num;
					l++;
				}
			}
		}
		
	}
	cout<<ans;
} 
