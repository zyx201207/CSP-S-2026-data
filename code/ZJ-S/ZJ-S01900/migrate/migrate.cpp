#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,a[N],b[N],l,r,ans,sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i]-a[1]; 
		}
		d++;
		ans=0;
		l=1,r=1;
		while(l<=r&&r<=n)
		{
			r++;
			while(l<=r)
			{
				sum=b[r]-b[l-1];
				if(sum>d)
				l++;
				else
				break;
			}
			if(sum==d&&r-l+1<=4)
			ans++;	
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
