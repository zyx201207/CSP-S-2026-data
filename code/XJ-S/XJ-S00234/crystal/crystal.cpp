#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500010];
ll inwith(int id){
	ll ans=1;
	ll tm=m;
	if(id==0)return ans;
	for (int i=id-1;i>=0;i--){
		if (a[id]-a[i]<=tm){
			tm-=(a[id]-a[i]);
			ans++;
		}
		else{
			return ans;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool specA=1,specB=1; 
	ll sub=0;
	for (int i=0;i<n;i++){
		cin >> a[i];
		if (a[i] != i+1) specA=0;
		if (i==1) sub=a[i]-a[i-1];
		else if (i!=0&&a[i]-a[i-1]!=sub)specB=0;
	}
	if (specB){
		int ans=0;
		ll k=0;
		for (int i=0;i<n;i++){
			k+=i*sub;
			if (k<=m) ans++;
		}
		cout <<ans;
		return 0;
	}
	sort(a,a+n);
	ll rt=0;
	for (int i=0;i<n;i++){
		rt=max(rt,inwith(i));
	}
	cout << rt;
	return 0;
} 
