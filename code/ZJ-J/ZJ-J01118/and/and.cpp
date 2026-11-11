#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,cnt;
int a[200100];
bool vis[200100],flag[200100];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	for(int j=30;j>=0;j--){
		memset(flag,0,sizeof flag);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1ll<<j)) flag[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(flag[i]&vis[i]) cnt++;
		}
		if(cnt>=m){
			ans+=(1ll<<j);
			for(int i=1;i<=n;i++) vis[i]=vis[i]&flag[i];
		}
	}
	cout<<ans;
}
