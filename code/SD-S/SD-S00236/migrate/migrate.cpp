#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
const int NN=5e3+10;
ll s[N];
int to[N];
int len[NN][NN];
ll sum[N];
int find(int l,int r,ll x){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(s[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
void solve(){
	int n;//2e6
	ll d;//2e18
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>s[i];//1e18
	}
	for(int i=1;i<=n;i++){
		to[i]=find(i,n,s[i]+d);
	}
	for(int i=1;i<=n;i++){
		int k=i,cnt=0;
		for(int j=i+1;j<=n;j++){
			k=to[k],cnt++;
			while(j<=k) len[i][j++]=cnt;
		}
	}
	ll ans=0;
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++) sum[i]=0;
		sum[l]=1;
		for(int r=l;r<=n;r++){
			if(len[l][r]!=len[l][r-1]){
				for(int i=to[r-1]-1;i>=r;i--) sum[i]+=sum[i+1];
			}
			if(len[l][to[r]]==len[l][r]+1) sum[to[r]]+=sum[r];
		}
		//for(int r=l;r<=n;r++) cout<<sum[r];
		for(int r=l;r<=n;r++) if(sum[r]==2) ans++;
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){//1e5
		solve();
	}
	return 0;
}
