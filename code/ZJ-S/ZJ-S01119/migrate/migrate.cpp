#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll c,T,n,d,i,dis[N][N],cnt[N][N],j,k,ans,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		memset(dis,127,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++){
			dis[i][i]=0;
			cnt[i][i]=1;
			for(j=i;j<=n;j++)
				for(k=j+1;k<=n;k++)
					if(a[k]-a[j]<=d){
						if(dis[i][j]+1==dis[i][k])
							cnt[i][k]+=cnt[i][j];
						else if(dis[i][j]+1<dis[i][k]){
							dis[i][k]=dis[i][j]+1;
							cnt[i][k]=cnt[i][j];
						}
					}
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cnt[i][j]==2)ans++;
		cout<<ans;
		if(T!=0)cout<<"\n";
	}
	return 0;
}

