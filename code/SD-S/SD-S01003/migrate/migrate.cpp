#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll dis[510][510];
ll f[510][510];
ll a[100100];
ll n,d,ans,c,t;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=300){
		memset(dis,0x3f,sizeof(dis));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				dis[i][j]=1;
				f[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<=n;j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						f[i][j]=f[i][k]*f[k][j]; 
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j])f[i][j]+=f[i][k]*f[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(f[i][j]==2)ans++;
		cout<<ans<<'\n';
		return;
	}
	d=d/(a[2]-a[1]);
	for(int i=1;i<d;i++)ans+=n-d-i+1;
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
