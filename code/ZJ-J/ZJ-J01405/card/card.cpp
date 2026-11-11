#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],f[N],w[N],q1[N],a1[N],n1=1;
void solve(){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[n])
		{
			sum1++;
			sum2++;
		}
		else if(a[i]==1)
		{
			sum1++;
		}
		else
		{
			sum2++;
		}
	}
	cout<<sum1<<' '<<sum2;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n>=2e5&&m==2)
	{
		solve();
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(f[a[j]]==0)
			{
				w[a[j]]=n1;
				a1[n1]=a[j];
				f[a[j]]=1;
			}
			else
			{
				for(int q=w[a[j]]+1;q<n1;++q)
				{
					f[a1[q]]=0;
					w[a1[q]]=0;
					a1[q]=0;
				}
				n1=w[a[j]];
			}
			n1++;
		}
		for(int q=1;q<=n1;++q)
		{
			q1[a1[q]]++;
		}
		for(int j=1;j<=n1;++j)
		{
			a1[j]=0;
		}
		for(int j=1;j<=m;++j)
		{
			f[j]=w[j]=0;
		}
		n1=1;
	}
	for(int i=1;i<=m;++i)
	{
		cout<<q1[i]<<' ';
	}
	return 0;
}             