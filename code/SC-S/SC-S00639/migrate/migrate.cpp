#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
while(t--)
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[2]-a[1]<=d)
			ans+=(i-2)/2;
		}
		cout<<ans<<endl;
		continue; 
	}
	cout<<0<<endl;
}
	return 0;
}
