#include<bits/stdc++.h>
using namespace std;
char sx[200010];
long long yzh[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>yzh[i]>>sx[i];
	}
	int l=1,r=n;
	int L=yzh[l],R=yzh[r];
	long long ans=0;
	while(l<=r)
	{
		if(sx[l]!=sx[r])
		{
			if(L==R)
			{
				ans+=L;
				l++,r--;
				L=yzh[l],R=yzh[r];
			}
			else if(L<R)
			{
				ans+=L;
				l++;
				R-=L;
				L=yzh[l];
			}
			else
			{
				ans+=R;
				r--;
				L-=R;
				R=yzh[r];
			}
		}
		else
		{
			if(L==R)
			{
				l++,r--;
				L=yzh[l],R=yzh[r];
			}
			else if(L<R)
			{
				l++;
				R-=L;
				L=yzh[l];
			}
			else
			{
				r--;
				L-=R;
				R=yzh[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
