#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],zd,zdsl;
void dfs(int cur,int last,int tot){
	if(tot>zd||cur>last){
		return ;
	}
	if(cur==last){
		if(tot==zd){
			zdsl++;
			return ;
		}
	}
	for(int i=cur+1;i<=n;i++){
		if(a[i]-a[cur]>d){
			break;
		}
		dfs(i,last,tot+1);
	}
}
int double_island(int l,int r){
	zd=1,zdsl=0;
	int uio=0;
	for(int i=l+1;i<=r;i++){
		int pio=a[i]-a[i-1];
		if(uio+pio>d){
			uio=0;
			zd++;
		}else{
			uio+=pio;
		}
	}
	dfs(l,r,0);
	return zdsl;
}
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(double_island(i,j)==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
