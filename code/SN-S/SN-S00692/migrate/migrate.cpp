#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cishu[5005][5005];
ll n,d;
ll a[5005];
ll min_go(ll i,ll j){
	ll k=j-1;
	if(a[j]-a[i]<=d)return 1;
	while(a[j]-a[k]<=d && k>=0){
		k--;
	}k++;
	if(k<=i)return -1;
	return cishu[i][k]+1;
}
ll next_should(ll l,ll should){
	for(ll i=l+1;a[i]-a[l]<=d;i++){
		if(a[i]-a[l]<should)continue;
		return i;
	}return -1;
}
ll next_num(ll l,ll should){
	ll num=0;
	for(ll i=l+1;a[i]-a[l]<=d;i++){
		if(a[i]-a[l]<should)continue;
		num++;
	}return num;
}
ll road(ll i,ll j,ll should,ll ci){
	if(i>j)return 0;
	if(i==j){
		if(ci<0)return 0;
		else return 1;
	}
	ll k=i+1,num=0;
	while(a[k]-a[i]<should && a[k]-a[i]<=d)k++;
	while(a[k]-a[i]<=d){
		num+=road(k,j,should,ci-1);
		k++;
	}return num;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ll c,t;
	cin>>c>>t;
	for(;t;t--){
		std::cin>>n>>d;
		ll ans=0;
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				cishu[i][j]=min_go(i,j);
			}
		}
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(cishu[i][j]<2)continue;
				ll should=(a[j]-a[i])/cishu[i][j];
				ll mn=road(i,j,should,cishu[i][j]);
				if(mn==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
