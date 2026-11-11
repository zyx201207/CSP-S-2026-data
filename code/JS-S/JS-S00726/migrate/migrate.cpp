#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,cnt,step;
long long a[2000006];
void dfs(int s,int num,int e)
{
	if(s>step||num>e) return;
	if(num==e)
	{
		if(s<step) step=s,cnt=1;
		else cnt++;
		//~ cout<<num<<" "<<s<<endl;
		return;
	}
	for(int i=n;i>=num+1;i--)
	{
		if(a[i]-a[num]<=d) dfs(s+1,i,e);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		//~ step=0x3f3f3f3f,cnt=0;
		//~ dfs(0,1,4);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d) continue;
				step=0x3f3f3f3f,cnt=0;
				if(c==13||c==14) step=2;
				dfs(0,i,j);
				if(cnt==2)
				{
					ans++;
					//~ cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
