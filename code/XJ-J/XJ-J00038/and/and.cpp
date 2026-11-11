#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,m,a[N],vis[N][35],f[N],v[40],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=a[i],cnt=1;
		f[i]=1;
		while(b){
			vis[i][cnt++]=b&1;
			b=b>>1;
		}
	}
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j])
				cnt+=vis[j][i];
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(f[j]==1){
					f[j]=vis[j][i];
				}
			}
			v[i]=1;
		}
	}
	long long base=1;
	for(int i=1;i<=31;i++){
		if(v[i])
			ans+=base;
		base*=2;
	}
	cout<<ans;
	return 0;
} 
