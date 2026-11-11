#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0,ans=0,p=1;
	for(ll i=1;i<=n;i++){
		sum+=a[i];
		while(p<=i&&a[i]*(i-p+1)-sum>m){
			sum-=a[p++];
		}
		if(p<=i)ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}