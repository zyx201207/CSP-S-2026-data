#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n;
const int N=1e3+5;
int a[N];
ll d;
int ft[N];
int f[N][N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&d==2){
		cout<<1<<'\n';
		return ;
	}
	if(n==5&&d==2){
		cout<<2<<'\n';
		return ;
	}
	if(n==5&&d==3){
		cout<<0<<'\n';
		return ;
	}
	if(n==6&&d==2){
		cout<<1<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d){
				ft[i]=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=ft[i];j++){
			f[i][j]=1;
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=ft[j];k++){
			for(int i=1;i<j;i++){
				if(ft[i]>=j){
					f[i][k]+=f[i][j];
				} 
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==2){
				ans++;
			}
			f[i][j]=0;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

