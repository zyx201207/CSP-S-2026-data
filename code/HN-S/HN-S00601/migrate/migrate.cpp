#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		long long dis[310][310]={};
		cin>>n>>d;
		bool f=1;
		int df[310][310]={};
		if(n<=300){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=LLONG_MAX;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dis[i][i+1]=dis[i+1][i]=1;
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
		}
		if(f==1){
			int k=d/(a[2]-a[1]);
			cout<<n-(k+2)+1<<endl;
			continue;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(i>=j)continue;
					if(a[k]-a[i]>d||a[j]-a[k]>d)continue;
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						df[i][j]=0;
						
					}
					else if(dis[i][k]+dis[k][j]==dis[i][j]){
						
						df[i][j]++;
					}
				}	
		for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i<j)
						if(df[i][j]==1)ans++;		
		cout<<ans<<endl;
	}
	return 0;
	
}
