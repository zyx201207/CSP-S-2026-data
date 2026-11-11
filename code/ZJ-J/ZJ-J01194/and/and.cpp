#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
int b[200010][35];
int c[35];
bool vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=0;
		while(a[i]){
			b[i][++x]=a[i]%2;
			a[i]/=2;
		}
	}
	for(int i=31;i>=1;i--){
		int x=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0)
				x+=b[j][i];
		}
		if(x>=m){
			c[i]=1;
			for(int j=1;j<=n;j++){
				if(vis[j]==0&&b[j][i]==0){
					vis[j]=1;
				}
			}
		}
	}
	int k=1,ans=0;
	for(int i=1;i<=31;i++){
		ans=ans+c[i]*k;
		k*=2;
	}
	cout<<ans;
	return 0;
}