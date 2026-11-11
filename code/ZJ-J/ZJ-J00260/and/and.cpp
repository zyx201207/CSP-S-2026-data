#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ans;
ll a[N],base[31];
ll b[N][31];
ll vis[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	base[0]=1;
	for(int i=1;i<=30;i++) base[i]=base[i-1]*2;
	for(int i=1;i<=n;i++){
		ll w=a[i];
		ll cnt=0;
		while(w){
			b[i][cnt]=w%2;
			w/=2;
			cnt++;
		}
	}
	for(int j=30;j>=0;j--){
		ll k=0;
		for(int i=1;i<=n;i++){
			if(b[i][j]==1&&vis[i]==0) k++;
		}
		if(k>=m){
			ans+=base[j];
			for(int i=1;i<=n;i++){
				if(b[i][j]==0) vis[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
