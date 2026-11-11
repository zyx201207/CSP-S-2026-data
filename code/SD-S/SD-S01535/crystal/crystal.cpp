#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

using namespace std;
typedef long long ll;
const int N=5e5+10;
const int INF=1e18+10;
ll a[N];
ll d[N];
ll s[N];
ll sum[N];
ll n,m; 

void solve1(){
	ll t=1,res=1,ans=0;
	for(int i=1; i<n; i++){
		ans=ans+t*(a[2]-a[1]);
		t++;
		if(ans<=m){
			res=i+1;
		}
	}
	cout<<res<<"\n";
	return;
}
int flag=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>100||a[i]<-100) flag=0;
	}
	
	if(n==1){
		cout<<1;
		return 0;
	}
	
	if(n>5000) solve1();

	sort(a+1,a+1+n);
	for(int i=1; i<n; i++){
		d[i]=a[i+1]-a[i];
		sum[i]=sum[i-1]+d[i];
		//cout<<sum[i]<<" "; 
	}
	//cout<<'\n';
	int t=1;
	for(int i=1; i<n; i++){
		s[i]=s[i-1]+d[i]*t;
		t++;
	}

	ll ans=1;
	for(int i=1; i<n; i++){
		int t=s[i];
		for(int j=1; j<=i; j++){
			if(t<=m){
				//cout<<t<<" "<<j<<" "<<i<<"\n";
				ans=max(ans,i-j+2);
				break;
			}
			t=t-(sum[i]-sum[j-1]);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5 
1 2 4 8 9
5 8
-3 -1 2 2 7

*/

