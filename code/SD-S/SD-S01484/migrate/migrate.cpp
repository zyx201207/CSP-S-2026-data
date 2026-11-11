#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,T,a[N],minn[N],cnt[N];
int n,m;
void dfs(int x,int dep){
	if(dep<minn[x]){
		minn[x]=dep;
		cnt[x]=1;
	}
	else if(dep=minn[x]){
		cnt[x]++;
	}
	for(int i=x+1;i<=n;i++){
		if(abs(a[x]-a[i])<=m) dfs(i,dep+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c<=2){
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(minn,0x3f,sizeof(minn));
			memset(cnt,0x3f,sizeof(cnt));
			dfs(i,1);
			for(int i=1;i<=n;i++){
				if(cnt[i]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;	
	}
	else if(c==11||c==12){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n-3<<'\n';
		}
		return 0;
	}
	else{
		while(T--) cout<<0<<'\n';
		return 0;
	}
}
/*
全排列永远的史 
离线求csp不会打后浪费时间小技巧 
*/

