#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ctnnd
ll c,t,n,d,a[200005],ans=0;
ll k[200002][200002];
ll D[200002][200002];
void solve(){
	ans=0;
	for(ll i=0;i<200002;i++){
		for(ll j=0;j<200002;j++){
			k[i][j]=0;
			D[i][j]=6767;
		}
	}
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<n;i++){
		for(ll l=1;l<n-i;l++){
			ll j=i+l;
			if(a[j]-a[i]>d*(j-i))continue;
			else if(a[j]-a[i]<=d){
				k[i][j]=1;
				D[i][j]=1;
			}
			else{
				for(ll v=i+1;v<j;v++){
					ll dd=D[i][v]+D[v][j],kk=k[i][v]*k[v][j];
					if(dd>D[i][j])continue;
					else if(dd==D[i][j]){
						k[i][j]+=kk;
					}
					else{
						k[i][j]=kk;
						D[i][j]=dd;
					}
					if(k[i][j]>2)continue;
				}
				if(k[i][j]==2)ans+=1;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
}
