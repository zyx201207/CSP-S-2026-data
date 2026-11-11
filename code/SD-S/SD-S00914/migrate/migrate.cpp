#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e6+10,Max=1e15;
int c,t,n,d,x[N],cnt,ans,sum;
inline void search(int u,int v,int w)
{
	if(w>ans)return;
	if(u==v)
	{
		if(ans==w)cnt++;
		if(ans>w)ans=w,cnt=1;	
		return;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(max(x[v]-x[i],x[i]-x[v])<=d)search(i,v,w+1);
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cnt=0;sum=0;ans=Max;
				search(i,j,1);
//				cout<<cnt<<'\n';
//				if(i==1&&j==4)cout<<cnt<<'\n';
				if(cnt==2)sum++;
//				if(cnt==2)cout<<i<<' '<<j<<' '<<ans<<'\n';
			}
		}cout<<sum<<'\n';
	}
	return 0;
}

