#include<bits/stdc++.h>
using namespace std;
set<int> s;
long long w[500005],k[505],a[505][10005],t[505][10005],b[500005],v[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==20||c==21)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>a[i][j]>>t[i][j];
				b[a[i][j]]+=1;
				v[a[i][j]]+=t[i][j];
			}
		}
		long long minn=1e12;
		for(int i=1;i<=m;i++)
		{
			if(b[i]==2)
			{
				minn=min(minn,v[i]);
			}
		}
		int x,y;
		while(q--)
		{
			cin>>x>>y;
			int xo=0,yo=0,xt=0,yt=0;
			long long ans=w[x]+w[y];
			for(int i=1;i<=k[1];i++)
			{
				if(a[1][i]==x)
				{
					xo=t[1][i];
				}
				if(a[1][i]==y)
				{
					yo=t[1][i];
				}
			}
			for(int i=1;i<=k[2];i++)
			{
				if(a[2][i]==x)
				{
					xt=t[2][i];
				}
				if(a[2][i]==y)
				{
					yt=t[2][i];
				}
			}
			if(xo&&yo&&xt&&yt)
			{
				cout<<min(min(ans+xo+yo,ans+xt+yt),min(ans+xo+minn+yt,ans+xt+minn+yo))<<endl;
			}else if(xo&&yo&&xt){
				cout<<min(ans+xo+yo,ans+yo+minn+xt)<<endl;
			}else if(xo&&yo&&yt){
				cout<<min(ans+xo+yo,ans+xo+minn+yt)<<endl;
			}else if(xo&&xt&&yt){
				cout<<min(ans+xt+yt,ans+xo+minn+yt)<<endl;
			}else if(yo&&xt&&yt){
				cout<<min(ans+xt+yt,ans+yo+minn+xt)<<endl;
			}else if(xo&&yo){
				cout<<ans+xo+yo<<endl;
			}else if(xt&&yt){
				cout<<ans+xt+yt<<endl;
			}else if(xo&&yt){
				cout<<ans+xo+minn+yt<<endl;
			}else if(yo&&xt){
				cout<<ans+yo+minn+xt<<endl;
			}
		}
	}
	return 0;
} 
