#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
#define ll long long
ll n,m,k,ans,a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1,cnt=0;
	while(r<=n){
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		while(r<=n&&cnt<=m){
			r++;
			if(r==n+1){
				break;
			}
			cnt+=(a[r]-a[r-1])*(r-l);
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}