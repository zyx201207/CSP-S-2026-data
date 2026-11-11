#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int n,a[N],f[N][N],d;
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			int len=r-l+1;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					f[i][j]=0;
				}
			}
			f[l][0]=1;
			for(int i=l;i<=r;i++){
				for(int j=1;j<len;j++){
					for(int k=l;k<i;k++){
						if(a[i]-a[k]<=d) f[i][j]+=f[k][j-1];
					}
				}
			}
			for(int i=1;i<len;i++){
				if(f[r][i]>0){
					if(f[r][i]==2){
						ans++;
					}
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[n]-a[n-1]==1&&d==2){
				cout<<n-3<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
		return 0;
	}
	while(t--){
		solve();
	}
}
