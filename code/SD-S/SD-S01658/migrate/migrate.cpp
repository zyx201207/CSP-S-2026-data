#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b){
	return a<=b;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int t1=1;t1<=t;t1++){
		int n;
		long long d;
		cin>>n>>d;
		vector<long long> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10||n<=300){
			vector<vector<long long> > dis(n+1,vector<long long>(n+1));
			vector<vector<int> > vis(n+1,vector<int>(n+1));
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					dis[i][j]=a[j]-a[i];
				}
			}
			for(int i=1;i<=n-d;i++){
				for(int j=i+d;j<=n;j++){
					for(int k=i+1;k<=j-1;k++){
						if(dis[i][k]+dis[k][j]==dis[i][j]){
							vis[i][j]++;
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(vis[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<0;
		}
	}
	return 0;
}
