#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N][35];
int b[N],n,m,ans;
int vis[N],c[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n;i++){
		int o=b[i];
		vis[i]=0;
		for(int j=30;j>=0;j--){
			if(o>=pow(2,j)){
				o-=pow(2,j);
				a[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if(a[i][j]==1){
				vis[i]+=j+1;
				c[vis[i]]=i;
			}
		}
	}
	sort(vis+1,vis+n+1,cmp);
	ans=b[vis[1]];
	for(int i=1;i<=n;i++){
		ans+=b[c[vis[i]]];
	}
	cout << ans;
	return 0;
}