//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int C,_,n,m,a[2000005],dist[2000005],ans,cnt[2000005];
//signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	freopen("migrate4.in","r",stdin);
////	freopen(".out","w",stdout);
//	cin>>C>>_;
//	while(_--){
//		cin>>n>>m;
//		ans=0;
//		for(int i=1;i<=n;i++) cin>>a[i];
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++) dist[j]=1e18,cnt[j]=0;
//			dist[i]=0,cnt[i]=1;
//			for(int j=i+1;j<=n;j++){
//				for(int k=j-1;k>=i&&a[j]-a[k]<=m;k--){
//					if(cnt[k]>2) continue;
//					if(dist[k]+1<dist[j]) cnt[j]=cnt[k],dist[j]=dist[k]+1;
//					else if(dist[k]+1==dist[j]) cnt[j]+=cnt[k];
//				}
////				cout<<i<<' '<<j<<' '<<dist[j]<<' '<<cnt[j]<<'\n';
//				ans+=(cnt[j]==2);
//			}
//		}
//		cout<<ans<<'\n';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,_,n,m,a[2000005],dist[2000005],ans,sum[2000005],ss[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>_;
	while(_--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dist[j]=1e18,sum[j]=ss[j]=0;
			dist[i]=0,sum[i]=1,ss[i]=1;
			int now=i,nnow=i;
			for(int j=i+1;j<=n;j++){
				while(now<j&&a[j]-a[now]>m) now++;
				if(now==j) break;
				while(nnow<j&&dist[nnow+1]==dist[now]) nnow++;
				dist[j]=dist[now]+1;
				if(ss[nnow]-ss[now-1]==2) ans++;
				sum[j]=ss[nnow]-ss[now-1];
				if(sum[j]>2) sum[j]=3;
				ss[j]=ss[j-1]+sum[j];
//				cout<<i<<' '<<j<<' '<<dist[j]<<' '<<now<<' '<<nnow<<' '<<sum[j]<<'\n';
//				cout<<ss[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}