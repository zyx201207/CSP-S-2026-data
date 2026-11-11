#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf double
#define vc vector
#define pb push_back
const ll N=1e3+5;
ll c,t,m,n,x,y;
ll a[N*N],d[N][N];
void solve1(){
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			ll s=i,cnt=1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[s]>m)cnt++,s=j-1;
				if(a[j]-a[s]>m)cnt=d[i][j]=1e15+7;
				d[i][j]=cnt;
//				cout<<i<<' '<<j<<' '<<d[i][j]<<'\n'; 
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ll cnt=0;
				for(int k=i+1;k<j;k++)if(d[i][k]+d[k][j]==d[i][j])cnt++
//				,cout<<k<<' '<<i<<' '<<j<<'\n'
				;
				if(cnt==2)ans++
//				,cout<<i<<' '<<j<<'\n'
				;
			}
		}
		cout<<ans<<'\n';
	}
}
void solve2(){
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++)cin>>x;
		cin>>y;
		if(y-x<=m&&m<y+y-x-x)cout<<n-2<<'\n';
		else cout<<"0\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(1<=c&&c<=10)solve1();
	if(11<=c&&c<=12)solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
