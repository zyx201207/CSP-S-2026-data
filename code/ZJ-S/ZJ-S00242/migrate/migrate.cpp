#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+5;
ll a[N],n,d;
void solve(){
	cin>>n>>d;
	bool ok=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>2){
			if(a[i]-a[i-1] != a[i-1]-a[i-2]) ok=0;
		}
	}
	if(ok){
		if(a[2]==a[1]){
			cout<<"0\n";
			return ;
		}
		d/=a[2]-a[1];
		if(d==0 || d==1){
			cout<<"0\n";
			return ; 
		}
		int j=2*d;
		cout<<max(0ll,n-j+1)<<'\n';
	}else if(a[n]-a[1]<=d){
		cout<<"0\n";
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<ll> f(n+1,1e9);
			vector<ll> g(n+1,0);
			f[i]=1;
			g[i]=1;
			for(int j=i;j<=n;j++){
				//cout<<g[j]<<" ";
				if(g[j]==2) ans++;
				for(int k=j+1;k<=n;k++){
					if(a[k]-a[j]<=d){
						if(f[k]==f[j]+1){
							g[k]+=g[j];
						}
						if(f[k]>f[j]+1){
							f[k]=f[j]+1;
							g[k]=g[j];
						}
					}else{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}


