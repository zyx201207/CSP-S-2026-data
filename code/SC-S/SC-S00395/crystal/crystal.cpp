#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
#define ll long long
ll n;
ll m;
ll a[maxn];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum=0;
	ll ans=0;
	ll l = 1;
	ll maxx=0;
	for(int r=1;r<=n;r++){
		ans++;
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
			ans--;
		}
		maxx  = max(maxx,ans);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 