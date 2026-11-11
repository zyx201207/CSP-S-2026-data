#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
     cin>>c>>t;
    while(t>0){
	t--;
	int n,d,a[20005],dis[5000][5000],ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dis[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int cnt=0;
			for(int k=i+1;k<=j-1;k++){
				if(cnt>2) break;
				if(dis[i][k]<=d&&dis[k][j]<=d){
					cnt++;
				}
			}
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<'\n';
}

	return 0;
} 