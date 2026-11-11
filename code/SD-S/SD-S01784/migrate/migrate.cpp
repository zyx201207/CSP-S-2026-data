#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c;
int t;
int n,d;
int x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int be=x[2]-x[1];
			int cnt=d/be;
			int sum=cnt;
		//	cout<<cnt<<"\n";
			int ans=0;
			cnt--;
			while(cnt>0)
			{
				
				ans=ans+n-(cnt+sum);cnt--;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
