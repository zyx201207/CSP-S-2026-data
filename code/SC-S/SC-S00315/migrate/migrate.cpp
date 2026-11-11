#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005;
int n,bef[maxn];
ll a[maxn],d,pre[maxn][maxn],f[maxn][maxn],g[maxn];
void solve(){
	cin>>n>>d;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],bef[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]>d)break;
			bef[i]=j;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)f[i][j]=pre[i][j]=0;
	for(int i=1;i<=n;i++){
		g[i]=0;
		int now=i;
		for(int j=i+1;j<=n;j++){
			if(bef[j]<=i)g[j]=1,f[i][j]=1;
			else {
				g[j]=g[bef[j]]+1;
				while(g[now+1]<=g[j]-1)now++;
				f[i][j]+=max(0ll,pre[i][now]-pre[i][bef[j]-1]); 
			}
			pre[i][j]=pre[i][j-1]+f[i][j];
			if(f[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int taskid,T;
	cin>>taskid>>T;
	while(T--)solve();
	return 0;
}
/*
1 1
10 3
-10 -7 -4 -3 -2 -1 0 1 4 7

-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/