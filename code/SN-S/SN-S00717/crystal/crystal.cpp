#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,dp[N][N];
ll a[N],m,c[N],str[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n+1;i++)c[i]=a[i-1]-a[i];
	ll mx=1;
	for(int i=2;i<=n+1;i++)str[i-1]=str[i-1]+c[i];
	for(int i=1;i<=n;i++){
		ll x=0,cn=0;
		while(x<=m&&cn+i<=n){
			x=x+str[i+cn]-str[i-1];
			cn++;
		}
		mx=max(mx,cn);
	}
	cout<<mx;
}
