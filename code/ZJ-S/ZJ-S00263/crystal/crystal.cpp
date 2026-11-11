#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num[500050],det[500050],ans=1,cnt=1,ind,tot;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=1;i<n;i++)
		det[i]=num[i+1]-num[i];
	for(int i=1;i<n;i++)
	{
		tot+=(1LL*det[i]*cnt);
		cnt++;
		while(tot>m)
		{
			tot-=(num[i+1]-num[++ind]);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
