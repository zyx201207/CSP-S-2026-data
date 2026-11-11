#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,vis[N];
int a[N],cnt[N];
struct st{
	int pre,nxt,x;
}b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[0]=(st){0,0,0};
	for(int l=1;l<=n;l++)
	{
		//memset(vis,0,sizeof(vis));
		int r=0;
		for(int i=l;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				b[a[i]]={r,0,a[i]};
				b[r].nxt=a[i];
				vis[a[i]]=1;
			}
			else
			{
				for(int j=b[a[i]].nxt;j!=0;j=b[j].nxt)
				vis[j]=0;
				b[a[i]].nxt=0;
			}
				r=a[i];
		}
		for(int i=b[0].nxt;i!=0;i=b[i].nxt)
		cnt[i]++,vis[i]=0;
		//cout<<i<<' ';
		//cout<<endl;
		
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}