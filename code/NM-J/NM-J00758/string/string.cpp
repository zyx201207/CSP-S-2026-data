#include<bits/stdc++.h>
using namespace std;
struct chuan{int sum;char x;}a[200100];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,t=1,w;
	long long ans=0;
	cin>>n,w=n;
	for(i=1;i<=n;++i) cin>>a[i].sum>>a[i].x;
	while(t<w)
	{
		if(a[t].x==a[w].x)//buyongtiao
		{
			if(a[t].sum<a[w].sum) 
			{
				a[w].sum-=a[t].sum;
				++t;
			}
			else 
			{
				if(a[t].sum>a[w].sum) 
				{
					a[t].sum-=a[w].sum;
					--w;
				}
				else 
				{
					++t;
					--w;
				}
			}
		}
		else
		{
			if(a[t].sum<a[w].sum) 
			{
				a[w].sum-=a[t].sum;
				ans+=a[t].sum;
				++t;
			}
			else 
			{
				if(a[t].sum>a[w].sum) 
				{
					a[t].sum-=a[w].sum;
					ans+=a[w].sum;
					--w;
				}
				else 
				{
					ans+=a[t].sum;
					++t;
					--w;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
