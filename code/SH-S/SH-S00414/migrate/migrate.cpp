#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,a[N];
struct node{
	int x,k;
};
int dis[N],cnt[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) cnt[j]=0,dis[j]=(int)4e18;
		dis[i]=0,cnt[i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(a[j]-a[k]<=d){
					dis[j]=min(dis[j],dis[k]+1);
				}
				else break;
			}
			for(int k=j-1;k>=i;k--){
				if(a[j]-a[k]<=d){
					if(dis[k]+1==dis[j]){
						cnt[j]++;
					}
				}
				else break;
			}
		}
		for(int j=i;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=a[2]-a[1];
	if(n==1||d/x<=1){
		cout<<"0\n";
		return;
	}
	int t=d/x*2;
	cout<<max(0ll,n-t+1)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		if(C==11||C==12) solve2();
		else solve();
	}
	return 0;
}
