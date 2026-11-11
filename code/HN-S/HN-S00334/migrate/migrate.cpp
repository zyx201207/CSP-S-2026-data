#include<bits/stdc++.h>
#define int long long
using namespace std;
string CSP="CSP RP++";
   
const int N=1e4+5;
    
int c,t,x[N],b[N][N],db[N][N];
    
signed main(){
   	freopen("migrate.in","r",stdin);
   	freopen("migrate.out","w",stdout);
   	
   	ios::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
   	
   	cin>>c>>t;
   	
   	while(t--)
   	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>x[i];
		memset(db,0,sizeof(db));
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(abs(x[i]-x[j])<k) b[i][j]=1;
				if(i==j) b[i][j]==0;
			}
		}
		
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(b[i][j]>b[i][k]+b[k][j])
					{
						b[i][j]=b[i][k]+b[k][j];
						if(db[i][j]!=1) db[i][j]=1;
					}
					else if(b[i][j]==b[i][k]+b[j][k])
					{
						db[i][j]=1;
					}
				}
			}
		}
		
		cout<<db[n][n]<<"\n";
   	}
   	return 0;
}   
