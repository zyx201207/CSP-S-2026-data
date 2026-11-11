#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int mintot,fs;
void dfs(int now,int ed,int d,int tot)
{
	if(now==ed)
	{
		if(tot>mintot) return;
		if(tot==mintot) fs++;
		if(mintot>tot) fs=1,mintot=tot;
		return;
	}
	for(int i=now+1;i<=ed;i++)
		if(x[i]-x[now]<=d) dfs(i,ed,d,tot+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++) 
			{
				mintot=0x3f3f3f3f,fs=0;
				dfs(u,v,d,0);
				if(fs==2) ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
