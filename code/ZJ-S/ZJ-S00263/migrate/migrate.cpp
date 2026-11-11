#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
int c,t,n,d,x[333],f[333][333],ans,book[333][333];
signed main()
{
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int l=1,tot=0;
		memset(f,0,sizeof(f));
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(x[j]-x[i]<=d)
					f[i][j]=1,book[i][j]=1;
				else
					break;
		for(int l=1;l<=n;l++)
		{
			for(int i=1;i<=n;i++)
			{
				int mins=inf,cnt=0;
				int j=i+l;
				if(j>n||f[i][j]==1) continue;
				if(book[j-1][j]==1&&f[j-1][j]==1&&f[j-2][j]!=1)
				{
					cnt=book[i][j-1];
					book[i][j]=book[i][j-1];
					f[i][j]=f[i][j-1]+1;
				}
				else
					for(int k=i+1;k<j;k++)
						if(f[i][k]&&f[k][j])
						{
							int tmp=f[i][k]+f[k][j];
							if(tmp<mins)
							{
								mins=tmp;
								cnt=book[i][k]*book[k][j];
							}
							else if(tmp==mins)
								cnt+=book[i][k]*book[k][j];
						}
				f[i][j]=mins;
				if(cnt==1)
					book[i][j]=0;
				else
					book[i][j]=cnt;
				if(cnt==2)
					ans++;
				//cout<<i<<" "<<j<<" "<<mins<<" "<<cnt<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
