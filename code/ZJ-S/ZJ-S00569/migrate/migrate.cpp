#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[200025];
long long dis[5025][5025];
long long ans;
void sv(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=4e18;
		}
	}for(int i=1;i<=n;i++){
		int p=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
		for(int j=i+1;j<=p;j++) dis[i][j]=1;
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}for(int i=1;i<=n;i++){
		int p=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
		if(p<=i+1) continue;
		for(int j=p+1;j<=n;j++){
			if(dis[p][j]==dis[p-1][j] and dis[p][j]!=4e18){
				if(i+2==p) ans++;
				else if(dis[p][j]!=dis[p-2][j]) ans++;
			}
		}
	}cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	while(t--) sv();
	return 0;
}
