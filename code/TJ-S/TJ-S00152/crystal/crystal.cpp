#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,maxn=1,cnt=0;
	for(ll r=2;r<=n;r++){
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(l<r){
			if(cnt<=m){
				maxn=max(maxn,r-l+1);
				break;
			}
			l++;
			cnt-=a[r]-a[l-1];
		}
	}
	cout<<maxn;
    return 0;
}

