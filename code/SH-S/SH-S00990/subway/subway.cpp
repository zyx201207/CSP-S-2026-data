#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q,w[514514];
struct node
{
	int k;int t;
};
vector<node> a[514514];
int edg[1145][1145];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=1;j<=x;j++)
		{
		    int kk,tt;cin>>kk>>tt;
		    a[kk].push_back((node){i,tt});
		}
	}
	memset(edg,0x3f,sizeof edg);
	for(int err=1;err<=m;err++)
	{
		for(int i=0;i<a[err].size();i++)
		{
			for(int j=0;j<i;j++)
			{
				int ii=a[err][i].k,jj=a[err][j].k,iw=a[err][i].t,jw=a[err][j].t;
				edg[jj][ii]=min(edg[jj][ii], iw+jw);
				edg[ii][jj]=edg[jj][ii];
			}
		}
	}
	
	
	for(int i=1;i<=n;i++)edg[i][i]=0;
	for(int g=1;g<=n;g++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(edg[i][j]>edg[i][g]+edg[g][j])edg[j][i]=edg[i][j]=edg[i][g]+edg[g][j];
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<edg[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int err=1;err<=q;err++)
	{
		int x,y;cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:a[x])
		{
			for(auto j:a[y])
			{
				ans=min(ans,w[x]+w[y]+i.t+j.t+edg[i.k][j.k]);
			}
		}
		cout<<ans<<"\n";
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[514514];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;cin>>n;
    freopen("subway.out","r",stdin);
    for(int i=1;i<=n;i++)
	cin>>a[i];
	
    freopen("subway4.ans","r",stdin);
    for(int i=1;i<=n;i++)
    {
    	int x;cin>>x;
    	if(x!=a[i])
		cout<<"Wrong Answer.On Line "<<i<<" ,read "<<a[i]<<" ,expected "<<x<<" ,laofeiwu\n";
	}
	cout<<"Accepted ok Accepted! !?long long?!";
}//checker
*/

