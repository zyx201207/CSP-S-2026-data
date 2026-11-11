#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans;
bool vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(a[j]&(1<<i))cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!vis[j]){
					if((a[j]&(1<<i))==0)vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
