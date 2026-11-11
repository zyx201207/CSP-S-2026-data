#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],ans,n,m;
map<ll,ll>t;
void ab(){
	for(ll i=1;i<=n;i++){
		t[a[i]]++;
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,t[a[i]]);
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){ab();}
	ll i=1,k=0,j=2;
	while(j<=n&&k<=m){
		j++;
		k+=(j-i)*(a[j]-a[j-1]);
	}
	ans=max(ans,j-i);
	cout<<ans;
	return 0;
}
