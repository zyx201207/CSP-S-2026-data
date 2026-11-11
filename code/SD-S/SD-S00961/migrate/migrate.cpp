#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],n,d;
int cnt=0,minn=0x7fffffffffffffff;
void dfs(int x,int y,int cnt1){
	if(x==y){
		if(minn>cnt1){
			minn=cnt1;
			cnt=1;
		}else{
			cnt++;
		}
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d) dfs(i,y,cnt1+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				minn=0x7fffffffffffffff;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
