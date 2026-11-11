#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000001],f[2000001],sum=0,n,d,minn;
void dfs(int x,int y,int k,int xz){
	if(k==y){
		if(minn==0x3f3f3f3f3f3f3f3f){
			minn=xz;
		}
		if(xz>minn){
			return;
		}
		sum++;
		return;
	}
	if(xz>minn){
		return;
	}
	for(int i=y;i>=k+1;i--){
		if(a[i]-a[k]>d){
			continue;
		}
		dfs(x,y,i,xz+1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=9){
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					minn=0x3f3f3f3f3f3f3f3f;
					sum=0;
					dfs(i,j,i,0);
					if(sum==2){
						cnt++;
					}
				}
			} 
			cout<<cnt<<'\n';
		}
		else{
			int ans=0;
			for(int i=3;i<=n;i++){
				if(i==d*2){
					ans=n-i+1;
					break;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
