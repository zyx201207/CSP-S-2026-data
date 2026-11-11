#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=1e18;
int c,T;
int n,d,minx,ans,nans;
int a[N];
void dfs(int x,int cnt,int maxn){
	cnt++;
	if(x==maxn){
		if(minx>cnt){
			minx=cnt;
			ans=1;
		}
		else if(minx==cnt) ans++;
		return;
	}
	for(int i=1;i<=d;i++){
		if(a[x+i]-a[x]>d || x+i>maxn) break;
		dfs(x+i,cnt,maxn);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				ans=0;
				minx=INF;
				dfs(i,0,j);
				if(ans==2) nans++;
			}
		}
		cout<<nans<<endl;
	}
	return 0;
}
