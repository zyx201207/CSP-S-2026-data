#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);i++)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);i--)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);i++)
typedef long long ll;
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'

template<typename T=int>T read(){T x;cin>>x;return x;}
const int N=5e5+5;
ll a[N],s[N];
int n;
ll m;
bool chk(int x){
	ll y=a[x],res=0;
	For(i,1,x-1){
		res+=y-a[i];
	}
	return res<=m;
}
void MAIN(){
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	if(n==1){
		cout<<1<<endl;
		return;
	}
	sort(a+1,a+n+1);
	For(i,1,n) s[i]=s[i-1]+a[i];
	ll ans=0;
	For(i,1,n){
		ll l=1,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) res=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;while(t--){
		MAIN();
	}
	return 0;
}
