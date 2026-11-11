#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const int N = 5005;

int n;
ll d, x[N];
int to[N], f[N][N], g[N][N];
void solve(){
	memset(f, 0x3f, sizeof(f));
	memset(g, 0, sizeof(g));
	cin>>n>>d;
	for(int i=1; i<=n; i++)cin>>x[i];
	for(int i=1; i<=n; i++){
		to[i]=i;
		for(int j=i-1; j>=1; j--){
			if(x[i]-x[j]>d)break;
			to[i]=j; 
		} 
	}
	ll ans=0;
	for(int i=1; i<=n; i++){
		f[i][i]=0;g[i][i]=1;
		for(int j=i+1; j<=n; j++){
			int l=max(i,to[j]);
			if(l==j)break;
			for(int k=l; k<j; k++){
				f[i][j]=min(f[i][j],f[i][k]);
			}
			for(int k=l; k<j; k++){
				if(f[i][k]==f[i][j]){
					g[i][j]+=g[i][k];
				}
			}
			f[i][j]+=1;
			if(g[i][j]==2)ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t; cin>>c>>t;
	while(t--)solve();
	return 0;
} 
