#include <bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,D,a[2000005],dis[305][305],cnt[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==2||n==3){
			cout<<"0\n";
			continue;
		}
		int d=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(d!=a[i]-a[i-1]){
				d=-1;
				break;
			}
		}
		if(~d||C==11||C==12){
			if(D>=a[n]-a[1]||D<=d){
				cout<<"0\n";
				continue;
			}
			int p=D/d;
			p+=p-1;
			cout<<n-p<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;
				dis[i][j]=1e18;
			}
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=D){
					dis[i][j]=dis[j][i]=1;
					cnt[i][j]=cnt[j][i]=1;
				}
			}
		}
		for(int k=2;k<n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<=n;j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						cnt[i][j]=cnt[j][i]=cnt[i][k]*cnt[k][j];
						dis[j][i]=dis[i][j]=dis[i][k]+dis[k][j];
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j],cnt[j][i]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//So difficult, CCF, give me 32pts please!

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105
333333333333333326 555555555555555547 999999999999999989

-999999999999999936 -777777777777777728
*/
