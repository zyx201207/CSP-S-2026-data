#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,a[500010],len,ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll l=1,r=1;r<=n;r++){
		sum+=(a[r]-a[r-1])*len++;
		while(sum>m)sum-=a[r]-a[l++],len--;
		ans=max(len,ans);
	}
	cout<<ans;
	return 0;
}
