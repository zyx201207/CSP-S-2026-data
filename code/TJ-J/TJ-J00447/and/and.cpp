#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 200099
using namespace std; 
ll n,m;
ll ans;
ll w[1000];
struct SSS{
	ll C;
	int W;
}a[N];
bool cmp(SSS A,SSS B){
	return A.C>B.C;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i].C;
		ll j=a[i].C,ww=0;
		while(j){
			j/=10;
			ww++;
		}w[ww]++;
		a[i].W=ww;
	}
	if(n==m){
		ans=a[1].C;
		for(ll i=2;i<=n;i++) ans=(ans&a[i].C);
		cout<<ans<<'\n';
		return 0;
	}else if(m==1){
		for(ll i=1;i<=n;i++)ans=max(ans,a[i].C);
		cout<<ans<<"\n";
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		if(w[a[i].W]>=m){
			for(ll j=1;j<=n;j++){
				if(ans==0&&a[j].W==a[i].W){
					ans=a[j].C;
				}else if(a[j].W==a[i].W){
					ans=(ans&a[j].C);
				}
			}cout<<ans<<'\n';
			return 0;
		}
	}ans=a[1].C;
	for(ll i=2;i<=n;i++){
		ans=(ans&a[i].C);
	}cout<<ans<<"\n";
	return 0;
}
