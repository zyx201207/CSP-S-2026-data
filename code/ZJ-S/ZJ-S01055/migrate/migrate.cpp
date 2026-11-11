#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,n,t,x,cnt,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	//if(c==0||c==11||c==12) 
	//{
		while(t--)
		{
			cin>>n>>d;
			if(n==1) 
			{
				cout<<0<<"\n";
				continue;
			}
			cin>>a>>b;
			for(long long i=3;i<=n;i++) cin>>x;
			cnt=b-a;
			ans=d/cnt;
			if(ans<2) 
			{
				cout<<0<<"\n";
				continue;
			}
			ans+=ans;
			cout<<max((long long)0,n-ans+1)<<"\n";
		}
	//}
	return 0;	
} 
