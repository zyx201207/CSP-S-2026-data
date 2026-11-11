#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,m,a[N];
ll l,r;
struct Node{ll l,sum,cnt;} k[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	k[1].l=1;
	k[1].cnt=1;
	k[1].sum=0;
	for(int i=2;i<=n;++i){
		k[i].sum=k[i-1].sum+k[i-1].cnt*(a[i]-a[i-1]);
		k[i].cnt=k[i-1].cnt+1;
		k[i].l=k[i-1].l;
		while(k[i].sum>m){
			k[i].sum-=(a[i]-a[k[i].l]);
			k[i].l++;
			k[i].cnt--;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,k[i].cnt);
	}
	cout<<ans<<endl;
	return 0;
}
