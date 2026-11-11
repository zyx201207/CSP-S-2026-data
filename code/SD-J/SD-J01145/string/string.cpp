#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
const int N=2e5+10;
pair<int,char>a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].f>>a[i].s;
	int l=1,r=n,ans=0ll;
	while(l<r)
	{
		while(a[l].f)
		{
			if(a[l].s!=a[r].s)
			{
				if(a[l].f>=a[r].f)
				{
					ans+=1ll*a[r].f;
					a[l].f-=a[r].f;
				}
				else
				{
					a[l].f=0;
					ans+=a[r].f;
				}
			}
			r--;
		}
		l++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
