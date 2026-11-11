#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,ans;
int a[N],cnt[N],dis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		dis[0]=-1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int s=1;s<=n;s++){
			for(int j=0;j<=n;j++) dis[j]=LONG_LONG_MAX;
//			for(int i=0;i<=n;i++) cnt[i]=0;
			dis[s]=0;
			int tag=s;
			for(int i=s;i<=n;i++){	
				if(dis[i]!=dis[i-1]){       //判断起始地点 
					for(int j=tag+1;j<=n;j++){
						if(a[j]-a[i]<=d){   //可飞 
							if(dis[i]+1<dis[j]){
								dis[j]=dis[i]+1;
								cnt[j]=1;
								tag=j;
							}
						}else break;
					}
				}else{
					for(int j=i+1;j<=n;j++){
						if(a[j]-a[i]<=d){
							if(dis[i]+1<dis[j]){
								dis[j]=dis[i]+1;
								cnt[j]=1;
								tag=j;
							}else if(dis[i]+1==dis[j]){
								cnt[j]++;
							}
						}
					}
				}
				
			}
//			cout<<s<<'\n';
//			for(int j=1;j<=n;j++) cout<<cnt[j]<<' '; cout<<'\n';
			for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		
		
		cout<<ans<<'\n';
	}
	
	
	return 0;
}