#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct edge{
	long long w;
	char c;
}a[N];
int n;
long long mid,l,r;
long long len;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i= 1;i<=n;i++)
	{
		cin >> a[i].w >> a[i].c;
		len += a[i].w;
	}
	l= 1,r = n;
	while(mid<len/2)
	{
		
		if(a[l].w>a[r].w)
		{
			
			mid += a[r].w;
			if(a[l].c!=a[r].c)
				ans+=a[r].w;
			a[l].w-=a[r].w;
			r--;
		}
		else if(a[l].w<a[r].w)
		{
			
			mid+=a[l].w;
			if(a[l].c!=a[r].c)
				ans+=a[l].w;
			a[r].w-=a[l].w;	
			l++;
		}
		else
		{
			if(a[l].c!=a[r].c)
				ans+=a[l].w;
			mid+=a[l].w;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
 
 
 
