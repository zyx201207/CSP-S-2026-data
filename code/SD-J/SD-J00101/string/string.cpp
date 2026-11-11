#include<bits/stdc++.h>
using namespace std;
int n;
long long g=0;
struct xxx{
	long long h;
	char c;
};
xxx a[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].h>>a[i].c;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].h>a[r].h)
			{
				a[l].h-=a[r].h;
				r--;
				
			}
			else if(a[l].h<a[r].h)
			{
				a[r].h-=a[l].h;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].h>a[r].h)
			{
				g+=a[r].h;
				a[l].h-=a[r].h;
				r--;
			}
			else if(a[l].h<a[r].h)
			{
				g+=a[l].h;
				a[r].h-=a[l].h;
				l++;
			}
			else
			{
				g+=a[r].h;
				a[r].h=0;
				a[l].h=0;
				l++;
				r--;
			}
		}
	}
	cout<<g;
	return 0;
} 
