#include<bits/stdc++.h>
using namespace std;;
int a[500005],end[300005],s[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		end[a[i]]=i;	
	}
	for(int i=1;i<=n;i++)
	{
		memset(s,sizeof(s),0);
		int cnt=i,id=1;
		while(cnt<=n)
		{
			cnt=end[a[cnt]];
			s[id]=a[cnt];
			cnt++;
			id++;
		}
		for(int j=1;j<=id-1;j++) ans[s[j]]++;
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
