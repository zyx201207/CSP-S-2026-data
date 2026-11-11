#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node 
{
	int len;
	char ch;	
}k[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].len>>k[i].ch;
	}
	int ans=0;
	int l=1,r=n;
	while(l!=r)
	{
		if(k[l].len>=k[r].len)
		{
			if(k[l].ch!=k[r].ch)
			{
				ans+=k[r].len;
			 } 
			k[l].len-=k[r].len;
			r--;
		}else{
			if(k[l].ch!=k[r].ch)
			{
				ans+=k[l].len;
			 } 
			k[r].len-=k[l].len;
			l++;
		} 
	}
	cout<<ans;
	return 0;
}

