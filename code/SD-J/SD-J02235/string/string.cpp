#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Member
{
	char ch;
	int num;
}a[200005];
int n;
signed main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int num,cur=1;
	char ch;
	for(int i=1;i<=n;i++)
	{
		cin>>num>>ch;
		if(a[cur-1].ch==ch)
		{
			a[cur-1].num+=num;
		}
		else
		{
			a[cur].ch=ch;
			a[cur].num=num;
			cur++;
		}
	}
	if(cur==1)
	{
		cout<<"0";
		return 0;
	}
	int cnt=0;
	int l=1,r=cur-1;
	while(l<=r)
	{
		if(a[l].num==a[r].num)
		{
			if(a[l].ch==a[r].ch)
			{
				l++,r--;
			}
			else
			{
				cnt+=a[l].num;
				l++,r--;
			}
		}
		else
		{
			if(a[l].ch!=a[r].ch)
			{
				if(a[l].num>a[r].num)
				{
					cnt+=a[r].num;
					a[l].num-=a[r].num;
					r--;
				}
				else
				{
					cnt+=a[l].num;
					a[r].num-=a[l].num;
					l++;
				}
			}
			else
			{
				if(a[l].num>a[r].num)
				{
					a[l].num-=a[r].num;
					r--;
				}
				else
				{
					a[r].num-=a[l].num;
					l++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
