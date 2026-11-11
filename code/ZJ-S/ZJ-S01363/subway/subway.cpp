#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[325000],k[3250],l[32500],a[32500][21],t[32500][21];
void fd(int )
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>bw>>t[bw][++l[bw]];
			a[bw][l[bw]]=i;
		}
	}
	for(int r=1;r<=q;r++)
	{
		int op,ed;
		cin>>op>>ed;
		memset(is,0,sizeof(is));
		fd(op) 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
