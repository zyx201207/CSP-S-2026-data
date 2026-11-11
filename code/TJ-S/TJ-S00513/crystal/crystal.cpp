#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a[500010];
ll diff[500010];
ll prediff[500010];
ll preprediff[500010];
ll need[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)diff[i]=a[i+1]-a[i];
	prediff[1]=diff[1];
	for(int i=2;i<n;i++)prediff[i]=prediff[i-1]+diff[i];
	preprediff[1]=prediff[1];
	for(int i=2;i<n;i++)preprediff[i]=preprediff[i-1]+prediff[i];
	need[1]=prediff[1];
	preprediff[0]=0;
	for(int i=2;i<=n;i++)need[i]=prediff[i-1]*(i-1)-preprediff[i-2];
	for(int i=n;i>=2;i--){
		if(need[i]<=m){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
