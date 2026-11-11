#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000010],jd[2000010],tmp=0;
void dfs(ll pos,ll la,ll en,ll mx,ll be)
{
	if(pos==mx+1)
	{
		if(mx==0)
		{
			if(x[en]-x[be]<=d)
			{
				tmp++;
//				cout<<tmp<<endl;
			}
			return;
		}
		if(x[en]-x[jd[pos-1]]<=d)
		{
//			cout<<jd[pos-1]<<" "<<mx<<" "<<be<<" "<<en<<endl;
			tmp++;
//			cout<<tmp<<endl;
		}
		return;
	}
	for(int i=la;i<=en-1;i++)
	{
		if(x[i]-x[la-1]<=d)
		{
			jd[pos]=i;
			dfs(pos+1,i+1,en,mx,be);
			jd[pos]=0;
		}
	}
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ll ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int fi=1;fi<=n;fi++)
		{
			for(int se=fi+1;se<=n;se++)
			{
				for(int s=0;s<=se-fi;s++)
				{
					tmp=0;
					dfs(1,fi+1,se,s,fi);
					if(tmp>=1&&tmp==2)
					{
//						cout<<fi<<" "<<se<<endl;
						ans++;
						break;
					}
					if(tmp>=1)
					{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

