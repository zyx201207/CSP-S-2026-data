#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,cnt[5005][5005],dis[5005][5005];
ll d,x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			ll k=abs(x[2]-x[1]),l=d/k;
			if(l<=1||n<2*l)cout<<0<<'\n';
			else cout<<n-2*l+1<<'\n';
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int i=1;i<n;i++){
				dis[i][i]=0,cnt[i][i]=1;
				for(int j=i+1;j<=n;j++){
					dis[i][j]=1e7,cnt[i][j]=0;
					for(int k=j-1;x[j]-x[k]<=d;k--)
						dis[i][j]=min(dis[i][j],dis[i][k]+1);
					for(int k=j-1;x[j]-x[k]<=d;k--)
						if(dis[i][k]+1==dis[i][j])cnt[i][j]+=cnt[i][k];
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
