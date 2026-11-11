#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,zt[500005],k,a[500005],t[500005],s,e,cnt,ans;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>zt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cnt+=k;
		for(int j=0;j<k;j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>s>>e;
		ans=0;
		ans+=zt[s]+zt[e];
		for(int j=0;j<cnt;j++)
		{
			if(a[j]==e||a[j]==s) ans+=t[j];
		}
		cout<<ans<<endl;
	}
	
	return 0;
 } 
