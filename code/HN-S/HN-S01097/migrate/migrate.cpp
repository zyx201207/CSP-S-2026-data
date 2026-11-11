#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000005;
int c,T,n;
ll d,a[N],ans;
int w[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			int l=i+1,r=i+1;
			while(a[r]<=a[i]+d)
				r++;
			r-=2;
			l=r-1;
			if(l<=i||r>=n)
				continue;
			int l_=upper_bound(a+l+1,a+r+d,a[l]+d)-a;
			int r_=lower_bound(a+r+d,a+l+1,a[r]+d)-a;
			if(l_!=r+d&&r_!=l+1&&l_<=r_)
			{
				ans+=r_-l_+1;
				w[i]=1;
			}
			
			for(int j=1;j<=i;j++)
				if(!w[j]&&w[i])
					ans++;
		}
		cout<<ans;
	}
	return 0;
}
