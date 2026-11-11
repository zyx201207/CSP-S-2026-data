#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],b[200005][35],m,ans,vis[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll id=0;
		while(a[i]>0){
			b[i][id]=a[i]%2;
			a[i]/=2;
			id++;
		}
	}
	for(int j=32;j>=0;j--){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(b[i][j]==1)cnt++;
			}
		}
		if(cnt>=m){
			ans*=2;
			ans++;
			for(int i=1;i<=n;i++){
				if(b[i][j]==0)vis[i]=1;
			}
		}
		else{
			ans*=2;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
