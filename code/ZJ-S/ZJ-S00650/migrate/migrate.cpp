#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int c,T;
int a[2000005];
int dis[305][305];
int cnt[305][305];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	#ifndef hyk0YF0Gamer
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int duel=1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				duel=0;
				break;
			}
		}
		if(duel==1){
			int g=upper_bound(a+1,a+n+1,
			a[1]+d)-a-2;
			if(g<=1){
				cout<<0<<'\n';
				continue;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int j=i+g+g-1;
				if(j>n)break;
				ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=0x3f3f3f3f;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d>=a[j]){
					dis[i][j]=1;
					cnt[i][j]=1;
				}
				else break;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],
					dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d<a[j])break;
				for(int k=j+1;k<=n;k++){
					if(a[j]+d<a[k])break;
					if(dis[i][j]+dis[j][k]
					==dis[i][k]){
						cnt[i][k]+=cnt[i][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558
-111111111111111116 111111111111111105
333333333333333326 555555555555555547
999999999999999989
*/
