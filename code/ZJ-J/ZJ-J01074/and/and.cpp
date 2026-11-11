#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],vis[200010],dis[200010];
int f[200010][35];
int x[200];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int aa=a[i],j=0;
		while(aa){
			if(aa&1){
				f[i][j]=1;
			}
			aa>>=1;
			j++;
		}
	}
	for(int j=31,cnt=0,no=0;j>=0;j--){
		for(int i=1;i<=n;i++){
			if(f[i][j]&&(!vis[i])){
				cnt++;
			}
		}
		if(cnt>=m){
			no=1;
		}
		if(cnt<m&&no){
			break;
		}
		if(no)
		for(int i=1;i<=n;i++){
			if(!f[i][j]){
				vis[i]=1;
			}
		}
		if(cnt==m){
			break;
		}
		cnt=0;
	}
	int ans=LLONG_MAX;
	for(int i=n;i>=1;i--){
		if(!vis[i]){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
