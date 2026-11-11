#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],road[2000005],h[2000005],ans,cnt;
int main()
{
//	freopen("mirgrate.in","r",stdin);
//	freopen("mirgrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]==1&&i!=1)
				cnt++;
		}
		ans=0;
		if(cnt+1==n)
			for(int i=1;i<=n-d;i++)
			{
				for(int j=1+d;j<=n;j++)
				{
					if(a[j]-a[i]==d+1)  ans++;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}//happy hollowween