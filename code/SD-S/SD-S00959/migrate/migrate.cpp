#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5005;
int n;
ll a[N],d;
int dis[N][N];
int cnt[N][N];
int pre[N],nxt[N];
int tmp[N];
int res[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],tmp[i]=0;
	for(int i=1,r=1;i<=n;i++){
		while(r<n&&a[r+1]-a[i]<=d) r++;
		nxt[i]=r;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=0;
			dis[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cnt[i][i]=1;
		nxt[i]=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) dis[i][j]=cnt[i][j]=1,nxt[i]=j;
			else break;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=nxt[i]+1;j<=n;j++){
			for(int k=i+1;k<=nxt[i];k++){
				if(a[k]-a[i]>d) break;
				if(dis[i][j]>1+dis[k][j]) dis[i][j]=1+dis[k][j],cnt[i][j]=0;
				if(dis[i][j]==1+dis[k][j]) cnt[i][j]+=cnt[k][j];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++,tmp[i]++;;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int CC,T;
	cin>>CC>>T;
	while(T--) solve();
	return 0;
}
