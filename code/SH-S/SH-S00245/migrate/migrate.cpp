#include<iostream>
using namespace std;
#define int long long
int n,d,a[2000001],f[2000001],v[2000001][3];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,ttt;
	cin>>c>>ttt;
	while(ttt--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		f[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			f[i]=f[i+1];
			while(a[i]+d<a[f[i]])f[i]--;
		}
		for(int i=n;i>=3;i--)
		{
			if(f[i]==i)
			{
				v[i][0]=v[i][1]=v[i][2]=0;
				continue;
			}
			if(f[i-2]==f[i-1]&&f[i-1]==f[i])v[i][1]=0;
			else if(f[i-1]==f[i])v[i][1]=v[f[i]][0]+f[i-1]-f[i-2];
			else if(f[i-1]+1==f[i]&&f[i-1]!=i)v[i][1]=v[f[i]][2]+f[i-1]-f[i-2];
			else v[i][1]=v[f[i]][1]+f[i-1]-f[i-2];
			if(f[i-1]==i&&f[i-2]==i-1)v[i][1]--;
			v[i][0]=v[f[i]][0]+f[i]-f[i-1];
			if(f[i]==f[i-1])v[i][0]=0;
			if(f[i]==f[i-1])v[i][2]=0;
			else if(f[i]==f[i-1]+1)v[i][2]=v[f[i]][2];
			else v[i][2]=v[f[i]][1];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i||f[i]==f[f[i]])continue;
			if(f[i]==i+1)ans+=v[f[i+1]][1];
			else if(f[i]==i+2)
			{
				if(f[i+1]==f[i+2])ans+=v[f[i+2]][0]+f[i+1]-i-2;
				else if(f[i+1]+1==f[i+2])ans+=v[f[i+2]][2]+f[i+1]-i-2;
				else ans+=v[f[i+2]][1]+f[i+1]-i-2;
			}
			else
			{
				if(f[f[i]-1]==f[f[i]-2]&&f[f[i]-1]==f[f[i]]);
				else if(f[f[i]-1]==f[f[i]])ans+=v[f[f[i]]][0]+f[f[i]-1]-f[f[i]-2];
				else if(f[f[i]-1]+1==f[f[i]])ans+=v[f[f[i]]][2]+f[f[i]-1]-f[f[i]-2];
				else ans+=v[f[f[i]]][1]+f[f[i]-1]-f[f[i]-2];
			}
		}
		cout<<ans<<'\n';
	}
}