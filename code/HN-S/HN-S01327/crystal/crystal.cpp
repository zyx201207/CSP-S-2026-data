#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5*1e5+10;
ll n,m,suo=0,sut=0,uu=0; 
ll a[MAXN],f[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll cs=m,cthtetofrte=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			cthtetofrte++;
		}
	}
	if(cthtetofrte==n){
		ll s=1,su=0;
		while(cs-s>=0){
			cs-=s;
			s++;
			su++;
		}
		cout<<su+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
		uu+=f[i];
	}
	uu-=f[1];
	if(m>=uu){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(cs-f[i]>=0){
			cs-=f[i];
			suo++;
		}
		else{
			break;
		}
	}
	cs=m;
	for(int i=n;i>=2;i--){
		if(cs-f[i]>=0){
			cs-=f[i];
			sut++;
		}
		else{
			break;
		}
	}
	suo++;
	sut++;
	cout<<max(suo,sut);
	return 0;
} 
