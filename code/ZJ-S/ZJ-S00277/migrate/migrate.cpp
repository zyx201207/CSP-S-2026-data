#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1;
ll a[N],d,n;
int g[N],fw[N];
int c,t;
void fil()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
ll solve(int L,int R)
{
	ll ans=0;
	for(int i=L;i<R;i++)
	{
		g[i]=0;fw[i]=1;
		int l=i;
		for(int j=i+1;j<=R;j++)
		{
			while(a[j]-a[l]>d)l++;
			g[j]=g[l]+1;fw[j]=fw[l];
			for(int o=1;o<=2;o++)if(l+o<j&&g[l+o]==g[l])fw[j]+=fw[l+o];
			if(fw[j]==2)ans++;
			if(fw[j]>3)fw[j]=3;
		}
	}
	return ans;
}
int main()
{
	fil();
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ls=1;ll ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>d&&i>1){if(ls<i-1)ans+=solve(ls,i-1);ls=i;}
		}
		if(ls<n)ans+=solve(ls,n);
		cout<<ans<<'\n';
	}
}
