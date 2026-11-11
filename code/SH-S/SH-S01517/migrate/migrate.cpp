#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000006;
int c,T,jm[302][302];
ll x[N];
bool okay(ll a,ll b,ll l,ll r){
	if((jm[l][a]==jm[l][b])&&(jm[a][r]==jm[b][r])) return 1;
	return 0;
}
void solveBF(ll n,ll d){
	memset(jm,0x3f,sizeof(jm));
	for(int i=1;i<=n;i++) jm[i][i]=0;
	for(int i=1;i<n;i++){
		ll nw=i;
		for(int j=1;j<n;j++){
			for(int k=nw+1;k<=n;k++){
				if(x[k]<=x[nw]+d) jm[i][k]=j;
				else{
					nw=k-1;
					continue;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<jm[i][j]<<" ";
		}
		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
			int cnt=0;
			for(int k=i+1;k<j;k++){
				if(okay(k,k-1,i,j)){
					cnt++;
					if(okay(k,k-2,i,j)) cnt++;
				}
				if(okay(k,k+1,i,j)){
					cnt++;
					if(okay(k,k+2,i,j)) cnt++;
				}
				if(cnt>=2) break;
			}
			if(cnt==1) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=300) solveBF(n,d);
		
	}
	return 0;
}
