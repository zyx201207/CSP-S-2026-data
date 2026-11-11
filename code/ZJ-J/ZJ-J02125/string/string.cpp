#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+15;
int n;
struct node{
	int x;
	char s;
}a[N];
string t;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	// 666 bei T2 zha pian le 
	// T2 yuan lai zhe me jian dan 
	// qi si wo lei
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s; 
	}
	int i=1,j=n;
	while(i<=j)
	{
		while(a[i].x)
		{
			if(a[i].s==a[j].s) 
			{
				if(a[i].x>=a[j].x)
				{
					a[i].x-=a[j].x;			
					j--;		
				}
				else
				{
					a[j].x-=a[i].x;
					a[i].x=0;
				}
			}
			else
			{
				if(a[i].x>=a[j].x)
				{
					a[i].x-=a[j].x;
					ans+=a[j].x;
					j--;
				}
				else
				{
					a[j].x-=a[i].x;
					ans+=a[i].x;
					a[i].x=0;
				}
			}
		}
		i++;
	}
	cout<<ans<<endl;
	// 9:41 AC
	// excellent 
}
