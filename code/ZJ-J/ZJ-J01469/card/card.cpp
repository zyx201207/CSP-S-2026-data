#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v(100);
ll i,j,n,m,cnt[1000005],f[1000005],a[1000005],k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		v.clear();
		memset(f,1,sizeof(f));
		for(j=i;j<=n;j++)
		{
			for(k=0;k<v.size();k++)
				if(a[j]==v[k]) break;
			if(k<=v.size()) 
			{
				for(ll k0=1;k0<=v.size()-k;k0++)
					v.pop_back();
			}
			v.push_back(a[j]);
		}
		for(j=0;j<v.size();j++)
			if(f[v[j]]) 
			{
				cnt[v[j]]++;f[v[j]]=0;
				//if(v[j]==2) cout<<i<<"\n";
			}
	}
	for(i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}