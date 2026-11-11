#include<bits/stdc++.h>//aaabbd
using namespace std;
#define int long long
int n,sum,ans,a[2000010];
char c[2000010];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(l<=r)
	{
		int mn=min(a[l],a[r]);

		if(c[l]!=c[r])
		{
			if(a[l]>a[r]) 
			{
				a[l]-=mn;
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=mn;
				l++;
			} 
			else l++,r--;
			ans+=mn;
		}
		else{
			if(a[l]>a[r]) 
			{
				a[l]-=mn;
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=mn;
				l++;
			} 
			else l++,r--;
		}
	}
	cout<<ans;
	return 0;
 } 
