#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll M=1e12+5;
int n;
ll m;
ll a[N];
ll cha[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	ll s=m;
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	sort(cha+1,cha+1+n);
	for(ll i=1;i<=m;i++){
		if(s==0) break;
		if(cha[i]<s){
			ans+=1;
			s-=i*cha[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}