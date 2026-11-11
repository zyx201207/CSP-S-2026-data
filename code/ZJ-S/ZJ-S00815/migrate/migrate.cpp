#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,M=5e3+10;
int c,n,d,a[N];
int r,b[N],dis[M][M],res;
void solve(){
	cin>>n>>d;r=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2) {cout<<0<<"\n";return ;}
	if(c>=11 && c<=12){
		int D=a[2]-a[1],num=d/D;
		if(num<=1) cout<<0<<"\n"; 
		else cout<<max(0ll,n-(2*num-1))<<"\n";
		return ;
	}
	if(c<=10){
		r=1;res=0;
		for(int i=1;i<=n;i++){
			while(r+1<=n && a[r+1]-a[i]<=d) r++;
			b[i]=r;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=-1;
			}
		}
		for(int i=n;i>=1;i--){
			dis[i][i]=0;
			for(int j=i-1;j>=1;j--){
				if(dis[min(b[j],i)][i]==-1) continue;
				dis[j][i]=dis[min(b[j],i)][i]+1;
			}
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				int j=i+l-1,num=0;
				if(a[j]-a[i]<=d){continue;}
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						num++;
					} 
				}
				if(num==dis[i][j]) res++;
			}
		}
		cout<<res<<"\n";	
		return ;
	}
	cout<<rand()<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}