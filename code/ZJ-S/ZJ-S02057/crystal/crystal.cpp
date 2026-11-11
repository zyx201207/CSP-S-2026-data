#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N];
ll ans;
ll xbb[N],jl[N],cj[N];
ll sq[N];
bool cmp(ll u,ll v){
	return u<v;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;i++){
		cj[i]=(a[i]-a[i-1]);
	}
	xbb[1]=1;
	jl[1]=0;
	for(ll i=2;i<=n;i++){
		xbb[i]=xbb[i-1];
		while((i-xbb[i-1])*cj[i]+jl[i-1]-sq[i] > m && xbb[i] <= i){
			sq[i] += (a[i]-a[xbb[i]]);
			++ xbb[i];
		}
		jl[i]=(i-xbb[i-1])*cj[i]+jl[i-1]-sq[i];
		ans=max(i-xbb[i]+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
