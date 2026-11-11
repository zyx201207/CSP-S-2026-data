#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,k,u,v,s[500][500],vvv;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{vvv=2e9;
		for(int i=1;i<=400;i++)
          for(int j=1;j<=400;j++)
            s[i][j]=0;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
			s[u][v]=1;
			s[v][u]=1;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
		      if(s[i][j]==1) {k--;vvv=min(vvv,n-j);break;}
		      if(k==0) break;
		}
		cout<<vvv/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
