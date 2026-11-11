#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],ans=0;
struct node{
	ll num,k;
}s[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=a[1];i<=a[n];i++){
		s[i].num=s[i-1].num+s[i-1].k,s[i].k=s[i-1].k;
		while(i>=a[s[i].k+1] && s[i].k+1<=n) s[i].k++;
	}
	ll l=a[1],r=a[n];
	while(l<=r){
		ll mid=(l+r)/2;
		if(s[mid].num>m) r=mid-1;
		else ans=max(ans,s[mid].k),l=mid+1;
	}
	cout<<ans;
	return 0;
} 
