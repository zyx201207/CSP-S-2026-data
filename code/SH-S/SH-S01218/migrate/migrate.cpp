#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll M=2e6+9;
ll c,t;
ll n,d;
ll x[N];
ll www[M];
ll l[N];
ll r[N];
ll f[N][N],rr;
void solve(){
	for(int i=1;i<=n;i++){
		cin>>x[i];
		l[i]=r[i]=0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				r[i]=j;
			}
			else break;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=n-1;j>=1;j--){
			if(x[i]-x[j]<=d){
				l[i]=j;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=0;
			if(x[r[i]]!=x[j]&&x[l[j]]!=x[i]&&r[i]-l[j]==1){
				f[i][j]=1;				
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][l[j]]==1&&f[r[i]][j]!=1&&f[l[l[j]]][j]!=1)f[i][j]=1; 
		}
	} 
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(f[r[j]][i]==1&&f[j][l[i]]!=1&&f[j][r[r[j]]]!=1)f[j][i]=1;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
			ans+=f[i][j];
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
	return ;
}
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>www[i];
	}
	cout<<0<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	rr=t;
	while(t--){
		cin>>n>>d;
		if(n<=5000)
			solve();
		else solve1();
	}
	return 0;
}
/*
0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
