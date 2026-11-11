#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll MOD=1e9+7;
const ll N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll C;
ll n,m,a[N],b[N],ma,c[N],d[N],e[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		b[i]=0;
		c[i]=0;
		cin>>a[i];
		if(i>1&&a[i-1]+m<a[i])c[i]=1;
	}
	ma=0;
	for(int i=1;i<=n-2;i++){
		if(a[i]+m>=a[i+2]){
			if(i==n-2||(a[i]+m<a[i+3]&&a[i+1]+m>=a[i+3]))b[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)d[j]=0,e[j]=0;
		d[i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[k]+m>=a[j]){
					if(e[j]==0)e[j]=e[k]+1,d[j]+=d[k];
					else{
						if(e[j]!=e[k]+1)break;
						d[j]+=d[k];
					}
				}
			}
			if(d[j]==2)ma++;
		}
	}
	cout<<ma<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;cin>>C>>T;
	while(T--)Solve();
	return 0;
}
