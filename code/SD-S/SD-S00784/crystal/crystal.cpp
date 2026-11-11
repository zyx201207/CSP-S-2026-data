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
const int N=5e5+5;
ll a[N],b[N],c[N],pre[N];
ll n,m;


//function
void solve(){
	
	
	return;
}
bool check(ll l,ll r,ll k){
	ll len=r-l+1;
	if(m>=len*k-(pre[r]-pre[l-1]))return true;
	else return false;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[++tot]=i;
			c[tot]=1;
		}
		else c[tot]++;
	}
	ll ans=0;
	for(int i=1;i<=tot;i++){
		ll l=1,r=b[i]-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,b[i]-1,a[b[i]]))r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,c[i]+(b[i]-1-r));
	}
	cout<<ans<<endl;
	
	//14:55 Finished
	//15:05 forget longlong 
	
	return 0;
}

