#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=5e5+5;
ll n,m;
ll a[maxn];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cnt=0;
	int l=1,r=1;
	while(r<n&&l<=r){
		int len=r-l+1;
		ans=max(ans,len);
		if((a[r+1]-a[r])*len+cnt<=m){
			cnt+=(a[r+1]-a[r])*len;
			++r;
		}
		else if(((a[r+1]-a[r])*(len-1))<a[r]-a[l]){
			cnt=(a[r+1]-a[r])*(len-1)+cnt;
			cnt-=a[r]-a[l];
			++r;
			++l;
		}
		else if(((a[r+1]-a[r])*(len-1))>a[r]-a[l]){
			cnt-=a[r]-a[l];
			++l;
		}
		else{
			++r;
			++l;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}