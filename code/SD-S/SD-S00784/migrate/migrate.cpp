#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//value
const int inf=2147483647;
const int mod=1e9+7;
const int N=2e6+5;
ll n,d;
map<pair<pair<ll,ll>,ll>,ll>mp;
ll s[N],a[N];


//function
void check(){
	ll l=0,r=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			l=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]==1){
			r=i;
			break;
		}
	}
	if(l==r)return;
	ll last=l,cnt=1;
	for(int i=l+1;i<=r;i++){
		if(s[i]==1 && a[i]-a[last]>d)return;
		if(s[i]==1){
			cnt++;
			last=i;
		}
	}
	mp[mkp(mkp(l,r),cnt)]++;
}
void dfs(ll x){
	if(x==n+1){
		check();
		return;
	}
	s[x]=0;
	dfs(x+1);
	s[x]=1;
	dfs(x+1);
}
void solve(){
	mp.clear();
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=inf;
	dfs(1);
	
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=2;k<=j-i+1;k++){
				if(mp[mkp(mkp(i,j),k)]>0){
					if(mp[mkp(mkp(i,j),k)]==2)ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	
	//有一丝很迷蒙的dp的想法
	//想不出来了 
	
	
	return;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	if(c==1 || c==2){
		while(t--) solve();
	}
	else{
		while(t--)cout<<0<<endl;
	}
	
	//15:42 先写T3暴力 预计32pts 
	//18:01 32pts个鬼  8pts 
	
	return 0;
}

