#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int x[N],far[N];
int minn=LONG_LONG_MAX,ans=1;
void dfs(int u,int ed,int sum){
	if(sum>minn){
		return;
	}
	if(u==ed){
		if(sum==minn){
			ans++;
			return;
		}else{
			minn=sum;
			ans=1;
			return;
		}
	}
	for(int i=far[u];i>=u+1;i--){
		dfs(i,ed,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int abc,T;
	cin>>abc>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int r=1;
		for(int l=1;l<=n;l++){
			while(x[r]-x[l]<=d){
				far[l]=r++;
			}
			r--;
		}
		int cnt=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				minn=LONG_LONG_MAX,ans=1;
				dfs(i,j,0);
				if(ans==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}